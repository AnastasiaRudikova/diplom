#include <ch.h>
#include <hal.h>

#include <chprintf.h>

int main(void)
{
    chSysInit();
    halInit();

    while (true)
    {
    	palToggleLine(LINE_LED3);
        chThdSleepSeconds(1);
    }
}
