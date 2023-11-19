#ifndef _UBX_MESSAGE_PROCESS_H
#define _UBX_MESSAGE_PROCESS_H

#include "ubx_message_parser.h"

void ubx_message_process_on_new_message(UBX_PARSER_STATE* input);
void ubx_message_process_on_tick();
void ubx_message_process_job(UBX_PARSER_STATE* msg);

#endif