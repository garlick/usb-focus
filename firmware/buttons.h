#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void buttons_setup (void);
EXTERNC void buttons_finalize (void);
EXTERNC void buttons_update (void);
