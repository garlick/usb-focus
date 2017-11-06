#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void stepper_setup (void);
EXTERNC void stepper_finalize (void);
EXTERNC void stepper_update (void);
