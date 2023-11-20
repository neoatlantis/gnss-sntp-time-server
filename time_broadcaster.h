
#ifndef _W5500_CONTROL_H    /* Guard against multiple inclusion */
#define _W5500_CONTROL_H

#include <time.h>

void time_broadcaster_init();
void time_broadcaster_on_time_update(struct tm* update);
void time_broadcaster_on_1pps();

#endif