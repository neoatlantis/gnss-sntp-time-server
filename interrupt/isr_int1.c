#include <xc.h>
#include <sys/attribs.h>
#include <stdint.h>
#include <stdio.h>
#include "init.h"
#include "../time_broadcaster.h"


void __ISR(_EXTERNAL_1_VECTOR, IPL7AUTO) isr_int1(){
    time_broadcaster_on_1pps();
    interrupt_int1_clear();
}