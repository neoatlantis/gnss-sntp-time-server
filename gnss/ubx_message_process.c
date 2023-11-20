#include <stdbool.h>
#include <stddef.h>
#include <time.h>
#include "ubx_message_parser.h"
#include "ubx_message_process.h"
#include "../time_broadcaster.h"

UBX_PARSER_STATE* new_ubx_message;

void ubx_message_process_on_new_message(UBX_PARSER_STATE* input){
    ubx_message_parser_set_inhibition(true);
    new_ubx_message = input;
}

void ubx_message_process_on_tick(){
    if(NULL == new_ubx_message) return;
    ubx_message_process_job(new_ubx_message);
    new_ubx_message = NULL;
    ubx_message_parser_set_inhibition(false);
}

void ubx_message_process_job(UBX_PARSER_STATE* msg){
    if(0x01 == msg->CLS && 0x21 == msg->INS && msg->bufferSize >= 18){
        // UBX-NAV-TIMEUTC
        struct tm next_tick;
        next_tick.tm_year = (msg->buffer[12] | (msg->buffer[13]<<8)) - 1900;
        next_tick.tm_mon  = msg->buffer[14];
        next_tick.tm_mday = msg->buffer[15];
        next_tick.tm_hour = msg->buffer[16];
        next_tick.tm_min  = msg->buffer[17];
        next_tick.tm_sec  = msg->buffer[18];
        time_broadcaster_on_time_update(&next_tick);
    }
}