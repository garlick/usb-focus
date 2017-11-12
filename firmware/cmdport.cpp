#include "WProgram.h"
#include "cmdport.h"

void cmdport_setup (void)
{
    Serial.begin(9600);
    Serial.println("Hello USB Focus Controller");
}

void cmdport_update (void)
{
}

void cmdport_finalize (void)
{
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
