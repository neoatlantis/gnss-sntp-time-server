#ifndef _SNTP_H
#define _SNTP_H

#include <stdint.h>


typedef union {
    uint8_t chars[4];
    struct {
        uint8_t MSB;
        uint8_t UMB;
        uint8_t LMB;
        uint8_t LSB;
    };
} SNTP_DWORD;
typedef SNTP_DWORD;

#define SNTP_DWORD_FILL(t, value) \
    t.MSB = (value >> 24) & 0xFF;\
    t.UMB = (value >> 16) & 0xFF;\
    t.LMB = (value >> 8) & 0xFF;\
    t.LSB = value & 0xFF;



typedef union {
    uint8_t chars[8];
    struct {
        SNTP_DWORD seconds;
        SNTP_DWORD fraction_seconds;
    };
} SNTP_TIMESTAMP;


typedef union {
    uint8_t ch;
    struct {
        unsigned MODE:3;
        unsigned VN:3;
        unsigned LI:2;
    };
} SNTP_MESSAGE_HEADER_PREAMBLE;


typedef union {
    uint8_t chars[4];
    struct {
        SNTP_MESSAGE_HEADER_PREAMBLE preamble;
        uint8_t STRATUM;
        uint8_t POLL;
        int8_t PRECISION;
    };
} SNTP_MESSAGE_HEADER;




typedef union {
    uint8_t chars[48];
    struct {
        SNTP_MESSAGE_HEADER header;
        SNTP_DWORD root_delay;
        SNTP_DWORD root_dispersion;
        SNTP_DWORD reference_identifier;
        SNTP_TIMESTAMP reference_timestamp;
        SNTP_TIMESTAMP originate_timestamp;
        SNTP_TIMESTAMP receive_timestamp;
        SNTP_TIMESTAMP transmit_timestamp;
    };
    
} SNTP_MESSAGE;

#define SNTP_MESSAGE_OFFSET_REFERENCE_TIMESTAMP 4*4
#define SNTP_MESSAGE_OFFSET_ORIGINATE_TIMESTAMP SNTP_MESSAGE_OFFSET_REFERENCE_TIMESTAMP + sizeof(SNTP_TIMESTAMP)
#define SNTP_MESSAGE_OFFSET_RECEIVE_TIMESTAMP   SNTP_MESSAGE_OFFSET_ORIGINATE_TIMESTAMP + sizeof(SNTP_TIMESTAMP)
#define SNTP_MESSAGE_OFFSET_TRANSMIT_TIMESTAMP  SNTP_MESSAGE_OFFSET_RECEIVE_TIMESTAMP + sizeof(SNTP_TIMESTAMP)



#endif