#include <AccelStepper.h>
#include "stepper.h"

/* Driving EasyDriver v44 with default strapping.
 * microstep mode = 1/8
 *
 * Testing with RoboFocus motor modified for bipolar operation.
 * The motor is geared for 0.1 deg/step.
 */

static const uint8_t step_pin = 11;
static const uint8_t direction_pin = 12;

static const int steps_per_revolution = 3600*8; // 0.1 deg/step, 1/8 microstep
static const int max_revolutions = 40;          // C8 tube ~40 turns

static const int high_limit = (max_revolutions * steps_per_revolution) / 2;
static const int low_limit = -1 * (max_revolutions * steps_per_revolution) / 2;

/* When manually focusing with the in/out buttons, acceleration is useful
 * for making fine adjustments with brief button presses, and coarse
 * adjustments with longer ones. We do want to stop quickly when focus
 * is reached, however.
 */
static float manual_acceleration = 1E2;
static float manual_deceleration = 1E6;

AccelStepper stepper (AccelStepper::DRIVER, step_pin, direction_pin);

void stepper_setup (void)
{
    stepper.setMaxSpeed (1000);
}

void stepper_update (void)
{
    stepper.run ();
}

void stepper_stop (void)
{
    stepper.setAcceleration (manual_deceleration);
    stepper.stop ();
}

void stepper_move_in (void)
{
    stepper.setAcceleration (manual_acceleration);
    stepper.moveTo (high_limit);
}

void stepper_move_out (void)
{
    stepper.setAcceleration (manual_acceleration);
    stepper.moveTo (low_limit);
}

void stepper_finalize (void)
{
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
