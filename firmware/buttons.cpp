#include <WProgram.h>
#include <Bounce.h>
#include "buttons.h"
#include "stepper.h"

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
    /* IN: move focal plane toward telescope
     */
    in.update ();
    if (in.risingEdge ())   // released
        stepper_stop ();
    if (in.fallingEdge ())  // pressed (active low)
        stepper_move_in ();

    /* OUT: move focal plane toward camera
     */
    out.update ();
    if (out.risingEdge ())  // released
        stepper_stop ();
    if (out.fallingEdge ()) // pressed (active low)
        stepper_move_out ();
}

void buttons_finalize (void)
{
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
