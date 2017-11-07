#include <WProgram.h>
#include "stepper.h"
#include "buttons.h"

int main (void)
{
    stepper_setup ();
    buttons_setup ();

    while (1) {
        stepper_update ();
        buttons_update ();
    }

    buttons_finalize ();
    stepper_finalize ();
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */

