#include <WProgram.h>
#include "stepper.h"

int main (void)
{
    stepper_setup ();

    while (1) {
        stepper_update ();
    }

    stepper_finalize ();
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */

