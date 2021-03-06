/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : SinalFalha.h
**     Project   : Lab1Questao1
**     Processor : MC9S12C128CFU16
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.16, CPU db: 2.87.411
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 10/03/2021, 15:33
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
**                       22            |  PB6_ADDR6_DATA6
**             ----------------------------------------------------
**
**         Port name                   : B
**
**         Bit number (in port)        : 6
**         Bit mask of the port        : $0040
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : up
**
**         Port data register          : PORTB     [$0001]
**         Port control register       : DDRB      [$0003]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool SinalFalha_GetVal(void);
**         PutVal - void SinalFalha_PutVal(bool Val);
**         ClrVal - void SinalFalha_ClrVal(void);
**         SetVal - void SinalFalha_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef SinalFalha_H_
#define SinalFalha_H_

/* MODULE SinalFalha. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG SinalFalha_CODE
/*
** ===================================================================
**     Method      :  SinalFalha_GetVal (component BitIO)
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
#define SinalFalha_GetVal() ( \
    (bool)((getReg8(PORTB) & 0x40U))   /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  SinalFalha_PutVal (component BitIO)
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
void SinalFalha_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  SinalFalha_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define SinalFalha_ClrVal() ( \
    (void)clrReg8Bits(PORTB, 0x40U)    /* BIT6=0x00U */ \
  )

/*
** ===================================================================
**     Method      :  SinalFalha_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define SinalFalha_SetVal() ( \
    (void)setReg8Bits(PORTB, 0x40U)    /* BIT6=0x01U */ \
  )

#pragma CODE_SEG DEFAULT

/* END SinalFalha. */
#endif /* #ifndef __SinalFalha_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
