#include <xc.h>
#include <sys/attribs.h>
#include <stdint.h>
#include <stdio.h>
#include "init.h"
#include "../w5500_control.h"


void __ISR(_EXTERNAL_1_VECTOR, IPL7AUTO) isr_int1(){
    w5500_broadcast_immediately();
    interrupt_int1_clear();
}