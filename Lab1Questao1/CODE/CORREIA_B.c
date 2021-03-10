/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CORREIA_B.c
**     Project   : Lab1Questao1
**     Processor : MC9S12C128CFU16
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.16, CPU db: 2.87.411
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 09/03/2021, 15:11
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       4             |  PP0_PWM0_KWP0
**             ----------------------------------------------------
**
**         Port name                   : P
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : $0001
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTP       [$0258]
**         Port control register       : DDRP      [$025A]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool CORREIA_B_GetVal(void);
**         PutVal - void CORREIA_B_PutVal(bool Val);
**         ClrVal - void CORREIA_B_ClrVal(void);
**         SetVal - void CORREIA_B_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE CORREIA_B. */

#include "CORREIA_B.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG CORREIA_B_DATA        /* Select data segment "CORREIA_B_DATA" */
#pragma CODE_SEG CORREIA_B_CODE
#pragma CONST_SEG CORREIA_B_CONST      /* Constant section for this module */
/*
** ===================================================================
**     Method      :  CORREIA_B_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool CORREIA_B_GetVal(void)

**  This method is implemented as a macro. See CORREIA_B.h file.  **
*/

/*
** ===================================================================
**     Method      :  CORREIA_B_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void CORREIA_B_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTP, 0x01U);           /* PTP0=0x01U */
  } else { /* !Val */
    clrReg8Bits(PTP, 0x01U);           /* PTP0=0x00U */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  CORREIA_B_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void CORREIA_B_ClrVal(void)

**  This method is implemented as a macro. See CORREIA_B.h file.  **
*/

/*
** ===================================================================
**     Method      :  CORREIA_B_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void CORREIA_B_SetVal(void)

**  This method is implemented as a macro. See CORREIA_B.h file.  **
*/


/* END CORREIA_B. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
