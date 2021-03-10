/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : DirecaoEsquerdaIn.c
**     Project   : Lab3Questao3
**     Processor : MC9S12C128CFU16
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.16, CPU db: 2.87.411
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 09/03/2021, 16:20
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       18            |  PB2_ADDR2_DATA2
**             ----------------------------------------------------
**
**         Port name                   : B
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : $0004
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PORTB     [$0001]
**         Port control register       : DDRB      [$0003]
**
**         Optimization for            : speed
**     Contents  :
**         SetDir - void DirecaoEsquerdaIn_SetDir(bool Dir);
**         GetVal - bool DirecaoEsquerdaIn_GetVal(void);
**         PutVal - void DirecaoEsquerdaIn_PutVal(bool Val);
**         ClrVal - void DirecaoEsquerdaIn_ClrVal(void);
**         SetVal - void DirecaoEsquerdaIn_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE DirecaoEsquerdaIn. */

#include "DirecaoEsquerdaIn.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG DirecaoEsquerdaIn_DATA /* Select data segment "DirecaoEsquerdaIn_DATA" */
#pragma CODE_SEG DirecaoEsquerdaIn_CODE
#pragma CONST_SEG DirecaoEsquerdaIn_CONST /* Constant section for this module */
/*
** ===================================================================
**     Method      :  DirecaoEsquerdaIn_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool DirecaoEsquerdaIn_GetVal(void)

**  This method is implemented as a macro. See DirecaoEsquerdaIn.h file.  **
*/

/*
** ===================================================================
**     Method      :  DirecaoEsquerdaIn_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void DirecaoEsquerdaIn_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PORTB, 0x04U);         /* BIT2=0x01U */
    Shadow_B |= 0x04U;                 /* Set-up shadow variable */
  } else { /* !Val */
    clrReg8Bits(PORTB, 0x04U);         /* BIT2=0x00U */
    Shadow_B &= 0xFBU;                 /* Set-up shadow variable */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  DirecaoEsquerdaIn_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**           a) direction = Input  : sets the output value to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void DirecaoEsquerdaIn_ClrVal(void)

**  This method is implemented as a macro. See DirecaoEsquerdaIn.h file.  **
*/

/*
** ===================================================================
**     Method      :  DirecaoEsquerdaIn_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**           a) direction = Input  : sets the output value to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void DirecaoEsquerdaIn_SetVal(void)

**  This method is implemented as a macro. See DirecaoEsquerdaIn.h file.  **
*/

/*
** ===================================================================
**     Method      :  DirecaoEsquerdaIn_SetDir (component BitIO)
**
**     Description :
**         This method sets direction of the component.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void DirecaoEsquerdaIn_SetDir(bool Dir)
{
  if (Dir) {
    setReg8(PORTB, (getReg8(PORTB) & (byte)(~(byte)0x04U)) | (Shadow_B & 0x04U)); /* BIT2=Shadow_B[bit 2] */
    setReg8Bits(DDRB, 0x04U);          /* BIT2=0x01U */
  } else { /* !Dir */
    clrReg8Bits(DDRB, 0x04U);          /* BIT2=0x00U */
  } /* !Dir */
}


/* END DirecaoEsquerdaIn. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
