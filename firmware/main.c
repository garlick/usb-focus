#include <WProgram.h>
#include "stepper.h"
#include "buttons.h"
#include "cmdport.h"

int main (void)
{
    stepper_setup ();
    buttons_setup ();
    cmdport_setup ();

    while (1) {
        stepper_update ();
        buttons_update ();
        cmdport_update ();
    }

    cmdport_finalize ();
    buttons_finalize ();
    stepper_finalize ();
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */

