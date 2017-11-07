#include <WProgram.h>
#include <Bounce.h>
#include "buttons.h"

const uint8_t in_button_pin = 14;
const uint8_t out_button_pin = 15;

static Bounce out_button = Bounce (out_button_pin, 5);
static Bounce in_button = Bounce (in_button_pin, 5);

void buttons_setup (void)
{
    pinMode (out_button_pin, INPUT);
    pinMode (in_button_pin, INPUT);
}

void buttons_update (void)
{
}

void buttons_finalize (void)
{
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
