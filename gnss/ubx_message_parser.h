#ifndef _UBX_MESSAGE_PARSER_H
#define _UBX_MESSAGE_PARSER_H

#include <stdint.h>
#include <stdbool.h>

#define UBX_PARSER_BUFFER_SIZE                  1024
#define UBX_PARSER_TIMEOUT_RESETVALUE           1000


enum UBX_PARSER_STATES {
    UBX_PARSER_WAITING_CHAR0,
    UBX_PARSER_WAITING_CHAR1,
    UBX_PARSER_WAITING_CLS,
    UBX_PARSER_WAITING_INS,
    UBX_PARSER_WAITING_LEN0,
    UBX_PARSER_WAITING_LEN1,
    UBX_PARSER_BUFFERING,
    UBX_PARSER_WAITING_CK_A,
    UBX_PARSER_WAITING_CK_B
};

typedef struct {
    enum UBX_PARSER_STATES state;
    uint8_t CLS;
    uint8_t INS;
    uint8_t EXTERNAL_CK_A;
    uint8_t EXTERNAL_CK_B;
    uint8_t buffer[UBX_PARSER_BUFFER_SIZE];
    uint16_t bufferSize;
    uint16_t bufferPointer;
    uint16_t timeoutCountdown;
} UBX_PARSER_STATE;

void ubx_message_parser_set_inhibition(bool);
void ubx_message_parser_reset();
void ubx_message_parser_on_tick();

UBX_PARSER_STATE* ubx_message_parser_recv_char(uint8_t c);

#define read16LE(buf, i) (buf[i] | (buf[i+1]<<8))

#endif
