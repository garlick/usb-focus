#include <AccelStepper.h>
#include "stepper.h"

const uint8_t step_pin = 11;
const uint8_t direction_pin = 12;

AccelStepper stepper (AccelStepper::DRIVER, step_pin, direction_pin);

int pos = 3600;

void stepper_setup (void)
{
    stepper.setMaxSpeed (2000);
    stepper.setAcceleration (1000);
}

void stepper_update (void)
{
    if (stepper.distanceToGo () == 0) {
        delay (500);
        pos = -pos;
        stepper.moveTo (pos);
    }
    stepper.run ();
}

void stepper_finalize (void)
{
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
