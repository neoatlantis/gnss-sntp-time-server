#ifndef _W5500_UDP_SOCKET_H
#define _W5500_UDP_SOCKET_H

#include <stdbool.h>
#include <stdint.h>
#include "../nic/nic.h"
#include "registers.h"
#include "spi.h"

void w5500_send_socket_command(NIC* nic, uint8_t socket_n, uint8_t command);
uint8_t w5500_get_socket_status(NIC* nic, uint8_t socket_n);
void w5500_open_udp_socket(NIC* nic, uint8_t socket_n, uint16_t port);

bool w5500_udp_socket_recv(NIC* nic, uint8_t socket_n, NICUDPPacket* udpp);
bool w5500_udp_socket_send(NIC* nic, uint8_t socket_n, NICUDPPacket* udpp);
uint16_t w5500_udp_socket_fill_txbuf(NIC*, uint8_t, NICUDPPacket*, uint8_t);

uint16_t w5500_udp_socket_send_deferred_ready(NIC*, uint8_t, NICUDPPacket*, bool);
void w5500_udp_socket_send_deferred_go(NIC* nic, uint8_t socket_n);


#endif