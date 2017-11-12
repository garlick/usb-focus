#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void cmdport_setup (void);
EXTERNC void cmdport_finalize (void);
EXTERNC void cmdport_update (void);

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
