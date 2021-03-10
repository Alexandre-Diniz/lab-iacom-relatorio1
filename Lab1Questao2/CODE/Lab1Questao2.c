/** ###################################################################
**     Filename  : Lab1Questao2.c
**     Project   : Lab1Questao2
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 08/11/2020, 11:26
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Lab1Questao2 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Sensor_A.h"
#include "Sensor_B.h"
#include "Sensor_C.h"
#include "Sensor_D.h"
#include "CORREIA_A.h"
#include "CORREIA_B.h"
#include "CORREIA_C.h"
#include "CORREIA_D.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
       
void main(void)
{
  /* Write your local variable definition here */


  int start = 1;
  bool A=0, B=0, C=0, D=0, CORREIA_A=0, CORREIA_B=0, CORREIA_C=0, CORREIA_D=0;
                

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */



do {

		   A = Sensor_A_GetVal();
		   B = Sensor_B_GetVal();
		   C = Sensor_C_GetVal();
		   D = Sensor_D_GetVal();
		   
		   CORREIA_A = !!A;
		   CORREIA_B = !A && B;
		   CORREIA_C = !A && !B && C;
		   CORREIA_D = !A && !B && !C && D;
		   
		   CORREIA_A_PutVal(CORREIA_A);
		   CORREIA_B_PutVal(CORREIA_B);
		   CORREIA_C_PutVal(CORREIA_C);
		   CORREIA_D_PutVal(CORREIA_D);

}while (start);

   

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END Lab1Questao1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
