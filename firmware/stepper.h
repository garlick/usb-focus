#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void stepper_setup (void);
EXTERNC void stepper_finalize (void);
EXTERNC void stepper_update (void);

/* Stop (quickly)
 */
EXTERNC void stepper_stop (void);

/* Move focal plane towards telescope (in) or camera (out), with acceleration.
 * Stop wtih stepper_stop().
 */
EXTERNC void stepper_move_in (void);
EXTERNC void stepper_move_out (void);

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
