/** ###################################################################
**     Filename  : Lab1Questao1.c
**     Project   : Lab1Questao1
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
/* MODULE Lab1Questao1 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Interruptor.h"
#include "Sensor_A.h"
#include "Sensor_B.h"
#include "Sensor_C.h"
#include "Eve.h"
#include "Evs.h"
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
  bool cond_Eve, cond_Evs, Sensor_A, Sensor_B, Sensor_C, Interruptor;
                

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */



do {

		   Interruptor = Interruptor_GetVal();
		   Sensor_A = Sensor_A_GetVal();
		   Sensor_B = Sensor_B_GetVal();
		   Sensor_C = Sensor_C_GetVal();
		   
		   cond_Eve = Interruptor && (!Sensor_A && (!Sensor_B || Sensor_C));
		   cond_Evs = Interruptor && Sensor_A && Sensor_B && Sensor_C;
		   
		   if(cond_Eve){
		       Eve_ClrVal();
		   } else {
		       Eve_SetVal();
		   }
		   
		   if(cond_Evs){
		       Evs_ClrVal();
		   } else {
		       Evs_SetVal();
		   }

}while (start);

   

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END Exp1Q1DiogoAbreu */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
