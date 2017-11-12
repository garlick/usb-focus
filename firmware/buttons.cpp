#include <WProgram.h>
#include <Bounce.h>
#include "buttons.h"

const uint8_t in_button_pin = 14;
const uint8_t out_button_pin = 15;

static Bounce in = Bounce (in_button_pin, 5);
static Bounce out = Bounce (out_button_pin, 5);

void buttons_setup (void)
{
    pinMode (in_button_pin, INPUT_PULLUP);
    pinMode (out_button_pin, INPUT_PULLUP);
}

void buttons_update (void)
{
    in.update ();
    if (in.risingEdge ())
        Serial.printf ("in button (rising)\n");
    if (in.fallingEdge ())
        Serial.printf ("in button (falling)\n");

    out.update ();
    if (out.risingEdge ())
        Serial.printf ("out button (rising)\n");
    if (out.fallingEdge ())
        Serial.printf ("out button (falling)\n");

}

void buttons_finalize (void)
{
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
