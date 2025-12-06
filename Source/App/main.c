#include "OS.h"
#include "EcuM.h"
#include "S32K144.h"

int main(void)
{
   Os_InitMemory();
   Os_Init();


  EcuM_Init(); /* never returns */

  return 0;
}


TASK(OsTask_Init)
{

 EcuM_StartupTwo();

 ISRType i;
 for (i = (ISRType)0; i < OS_ISRID_COUNT; i++)
 {
   Os_EnableInterruptSource(i, TRUE);
 }

 (void)TerminateTask();
}











