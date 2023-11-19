/*
 * File:   gpsread.c
 * Author: standard
 *
 * Created on 2023年9月12日, 下午10:13
 */


#include <xc.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "ubx_message_parser.h"


UBX_PARSER_STATE ubx_parser_state = {
    .state = UBX_PARSER_WAITING_CHAR0,
    .bufferSize = 0,
    .bufferPointer = 0,
    .timeoutCountdown = UBX_PARSER_TIMEOUT_RESETVALUE
};
bool ubx_message_parser_inhibited = false;


struct ubx_parser_checksum_calc {
    uint8_t CK_A;
    uint8_t CK_B;
} ubx_parser_checksum_calc;

void ubx_parser_checksum_reset(){
    ubx_parser_checksum_calc.CK_A = 0;
    ubx_parser_checksum_calc.CK_B = 0;
}

void ubx_parser_checksum_update(uint8_t c){
    ubx_parser_checksum_calc.CK_A = ubx_parser_checksum_calc.CK_A + c;
    ubx_parser_checksum_calc.CK_B = 
        ubx_parser_checksum_calc.CK_B + ubx_parser_checksum_calc.CK_A;
}











void ubx_message_parser_reset(){
    ubx_parser_state.state = UBX_PARSER_WAITING_CHAR0;
    ubx_parser_state.bufferSize = 0;
    ubx_parser_state.bufferPointer = 0;
    ubx_parser_state.timeoutCountdown = UBX_PARSER_TIMEOUT_RESETVALUE;
}


void ubx_message_parser_on_tick(){
    // ubx parser has a countdown, which is updated by external timer ticks.
    ubx_parser_state.timeoutCountdown -= 1;
    if(
        0 == ubx_parser_state.timeoutCountdown &&
        UBX_PARSER_WAITING_CHAR0 != ubx_parser_state.state
    ){
        // timed out, reset parser
        ubx_message_parser_reset();
    }
}

void ubx_message_parser_set_inhibition(bool v){
    ubx_message_parser_inhibited = v;
}

UBX_PARSER_STATE* ubx_message_parser_recv_char(uint8_t c){
    if(ubx_message_parser_inhibited) return NULL;
    switch(ubx_parser_state.state){
    case UBX_PARSER_WAITING_CHAR0:
        if(0xb5 == c){
            // start reception
            ubx_parser_state.state = UBX_PARSER_WAITING_CHAR1;
            // set up timeout countdown
            ubx_parser_state.timeoutCountdown = UBX_PARSER_TIMEOUT_RESETVALUE;
        }
        break;
    case UBX_PARSER_WAITING_CHAR1:
        if(0x62 == c){
            ubx_parser_state.state = UBX_PARSER_WAITING_CLS;
            ubx_parser_checksum_reset();
        }
        break;
    case UBX_PARSER_WAITING_CLS:
        ubx_parser_state.CLS = c;
        ubx_parser_state.state = UBX_PARSER_WAITING_INS;
        ubx_parser_checksum_update(c);
        break;
    case UBX_PARSER_WAITING_INS:
        ubx_parser_state.INS = c;
        ubx_parser_state.state = UBX_PARSER_WAITING_LEN0;
        ubx_parser_checksum_update(c);
        break;
    case UBX_PARSER_WAITING_LEN0:
        ubx_parser_state.bufferSize = c;
        ubx_parser_checksum_update(c);
        ubx_parser_state.state = UBX_PARSER_WAITING_LEN1;
        break;
    case UBX_PARSER_WAITING_LEN1:
        ubx_parser_state.bufferSize |= (c << 8);
        ubx_parser_checksum_update(c);
        ubx_parser_state.bufferPointer = 0;
        // CHECK BUFFER AVAILABILITY
        if(ubx_parser_state.bufferSize > UBX_PARSER_BUFFER_SIZE){
            // error, reset
            ubx_message_parser_reset();
        } else {
            ubx_parser_state.state = UBX_PARSER_BUFFERING;
        }
        break;
    case UBX_PARSER_BUFFERING:
        ubx_parser_checksum_update(c);
        ubx_parser_state.buffer[ubx_parser_state.bufferPointer] = c;
        ubx_parser_state.bufferPointer += 1;
        if(ubx_parser_state.bufferSize == ubx_parser_state.bufferPointer){
            // received expected length, go next
            ubx_parser_state.state = UBX_PARSER_WAITING_CK_A;
        }
        break;
    case UBX_PARSER_WAITING_CK_A:
        ubx_parser_state.EXTERNAL_CK_A = c;
        ubx_parser_state.state = UBX_PARSER_WAITING_CK_B;
        break;
    case UBX_PARSER_WAITING_CK_B:
        ubx_parser_state.EXTERNAL_CK_B = c;
        ubx_parser_state.state = UBX_PARSER_WAITING_CHAR0;
        if(
            ubx_parser_state.EXTERNAL_CK_A == ubx_parser_checksum_calc.CK_A &&
            ubx_parser_state.EXTERNAL_CK_B == ubx_parser_checksum_calc.CK_B
        ){
            return &ubx_parser_state;
        }
    }

    return NULL;
}
