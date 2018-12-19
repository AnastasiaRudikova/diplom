#include <ch.h>
#include <hal.h>
#include <chprintf.h>

GPTConfig gpt4conf = {
    .frequency    = 10000,
    .callback     = NULL,
    .cr2          = 0,
    .dier         = 0
};

int main(void)
{
//    chSysInit();
    halInit();

    GPTDriver *delayDriver    = &GPTD4;

    gptStart( delayDriver, &gpt4conf );

    while (true)
    {
    palSetLine( LINE_LED1);
    gptPolledDelay( delayDriver, 2500 );
    palClearLine( LINE_LED1);
    gptPolledDelay( delayDriver, 1000 );
    palSetLine( LINE_LED2);
    gptPolledDelay( delayDriver, 2500 );
    palClearLine( LINE_LED2);
    gptPolledDelay( delayDriver, 1000 );
    palSetLine( LINE_LED3);
    gptPolledDelay( delayDriver, 2500 );
    palClearLine( LINE_LED3);
    gptPolledDelay( delayDriver, 1000 );
    }
}
