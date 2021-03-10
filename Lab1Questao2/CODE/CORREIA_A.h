/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CORREIA_A.h
**     Project   : Lab1Questao2
**     Processor : MC9S12C128CFU16
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.16, CPU db: 2.87.411
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 10/03/2021, 01:16
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
**                       20            |  PB4_ADDR4_DATA4
**             ----------------------------------------------------
**
**         Port name                   : B
**
**         Bit number (in port)        : 4
**         Bit mask of the port        : $0010
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PORTB     [$0001]
**         Port control register       : DDRB      [$0003]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool CORREIA_A_GetVal(void);
**         PutVal - void CORREIA_A_PutVal(bool Val);
**         ClrVal - void CORREIA_A_ClrVal(void);
**         SetVal - void CORREIA_A_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef CORREIA_A_H_
#define CORREIA_A_H_

/* MODULE CORREIA_A. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG CORREIA_A_CODE
/*
** ===================================================================
**     Method      :  CORREIA_A_GetVal (component BitIO)
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
#define CORREIA_A_GetVal() ( \
    (bool)((getReg8(PORTB) & 0x10U))   /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  CORREIA_A_PutVal (component BitIO)
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
void CORREIA_A_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  CORREIA_A_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define CORREIA_A_ClrVal() ( \
    (void)clrReg8Bits(PORTB, 0x10U)    /* BIT4=0x00U */ \
  )

/*
** ===================================================================
**     Method      :  CORREIA_A_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define CORREIA_A_SetVal() ( \
    (void)setReg8Bits(PORTB, 0x10U)    /* BIT4=0x01U */ \
  )

#pragma CODE_SEG DEFAULT

/* END CORREIA_A. */
#endif /* #ifndef __CORREIA_A_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
