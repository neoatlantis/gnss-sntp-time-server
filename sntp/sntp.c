#include "sntp.h"

void sntp_message_new_server_broadcast(SNTP_MESSAGE* msg){
    msg->header.preamble.LI = 0;
    msg->header.preamble.VN = 4;
    msg->header.preamble.MODE = 5;
    msg->header.STRATUM = 1;
    msg->header.PRECISION = -9; // 1/2^-9 = 1/512 seconds
    msg->header.POLL = 9;
    
    SNTP_DWORD_FILL(msg->root_delay, 0);
    SNTP_DWORD_FILL(msg->root_dispersion, 0);
    
    msg->reference_identifier.chars[0] = 'G';
    msg->reference_identifier.chars[1] = 'P';
    msg->reference_identifier.chars[2] = 'S';
    msg->reference_identifier.chars[3] = 0;
}