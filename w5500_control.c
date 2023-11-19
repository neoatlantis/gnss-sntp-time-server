#include <string.h>
#include "nic/nic.h"
#include "w5500/new.h"
#include "w5500/udp_socket.h"
#include "w5500_control.h"
#include "customized_params.h"

NIC nic;

void w5500_select(){
    spi2_set_mode_8();
    spi2_slot2_select();
}

void w5500_deselect(){
    spi2_deselect_all();
}

void w5500_init(){
    nic.id = 0;
    memcpy(&nic.mac.octet,       &(uint8_t[6]){ 0x02, 0x20, 0x07, 'J', 'V', 0x22 }, 6);
    memcpy(&nic.ip_device.octet, &(uint8_t[4]){ LOCAL_IP }, 4);
    memcpy(&nic.ip_netmask.octet,&(uint8_t[4]){ NETMASK }, 4);
    nic.driver.spi_select = w5500_select;
    nic.driver.spi_deselect = w5500_deselect;
    nic.driver.spi_exchange_register = spi2_exchange_buffer;
    
    w5500_new(&nic);
    
    printf("Initialize W5500 at slot 1...\n\r");
    nic.init(&nic);
    
    printf("Opening UDP port at slot 1...\n\r");
    w5500_open_udp_socket(&nic, 0, 123);
    
    printf("Init done.\n\r");
}


void w5500_broadcast_immediately(){
    
};