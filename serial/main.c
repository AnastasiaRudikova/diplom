#include <ch.h>
#include <hal.h>
#include <chprintf.h>

static const SerialConfig sdcfg = {
    .speed  = 115200,
    .cr1    = 0,
    .cr2    = 0,
    .cr3    = 0
};

int main(void)
{
    chSysInit();
    halInit();

    sdStart( &SD7, &sdcfg );
    palSetPadMode( GPIOE, 8, PAL_MODE_ALTERNATE(8) ); // TX
    palSetPadMode( GPIOE, 7, PAL_MODE_ALTERNATE(8) ); // RX

    while (true)
    {
      chprintf(((BaseSequentialStream *)&SD7), "Robots run the world!\r");
      chThdSleepSeconds( 1 );
    }
}
