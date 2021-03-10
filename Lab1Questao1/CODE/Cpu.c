/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cpu.c
**     Project   : Lab1Questao1
**     Processor : MC9S12C128CFU16
**     Component : MC9S12C32_80
**     Version   : Component 02.001, Driver 02.06, CPU db: 2.87.411
**     Datasheet : MC9S12C128 Rev 01.23 05/2007
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 10/03/2021, 15:33
**     Abstract  :
**         This component "MC9S12C32_80" implements properties, methods,
**         and events of the CPU.
**     Settings  :
**
**     Contents  :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Cpu. */

#include "Sensor_A.h"
#include "Sensor_B.h"
#include "Sensor_C.h"
#include "Eve.h"
#include "Evs.h"
#include "Interruptor.h"
#include "SinalFalha.h"
#include "Events.h"
#include "Cpu.h"

#define CGM_DELAY  0x03FFU

#pragma DATA_SEG DEFAULT               /* Select data segment "DEFAULT" */
#pragma CODE_SEG DEFAULT


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR reegister */
#pragma CODE_SEG __NEAR_SEG NON_BANKED


/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MC9S12C32_80)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S12C32_80)
**
**     Description :
**         Disable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S12C32_80)
**
**     Description :
**         Enable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component MC9S12C32_80)
**
**     Description :
**         Set low power mode - Stop mode.
**         For more information about the stop mode see
**         documentation of this CPU.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetStopMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component MC9S12C32_80)
**
**     Description :
**         Set low power mode - Wait mode.
**         For more information about the wait mode see
**         documentation of this CPU.
**         Release from Wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetWaitMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S12C32_80)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab of the CPU component. !!! ***/


#pragma CODE_SEG __NEAR_SEG NON_BANKED

#define INITRG_ADR  0x11U              /* Register map position register */

#pragma NO_FRAME                       /* Suppress generation of frame code */
#pragma NO_EXIT                        /* Suppress generation of exit from a function */
void _EntryPoint(void)
{

  /*** !!! Here you can place your own code using property "User code before PE initialization" on the build options tab of the CPU compoennt. !!! ***/

  /* ### MC9S12C32_80 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Initialization of the registers INITRG, INITRM, INITEE is done to protect them to be written accidentally later by the application */
  /*lint -save  -e950 -e923 Disable MISRA rule (1.1,11.3) checking. */
  *(byte*)INITRG_ADR = 0x00U;          /* Set the register map position */
  asm("nop");                          /* nop instruction */
  /*lint -restore Enable MISRA rule (1.1,11.3) checking. */
  /* INITRM: RAM15=0,RAM14=0,RAM13=1,RAM12=1,RAM11=1,??=0,??=0,RAMHAL=1 */
  setReg8(INITRM, 0x39U);              /* Set the RAM map position */ 
  /* MISC: ??=0,??=0,??=0,??=0,EXSTR1=1,EXSTR0=1,ROMHM=0,ROMON=1 */
  setReg8(MISC, 0x0DU);                 
  /* PEAR: NOACCE=0,??=0,PIPOE=0,NECLK=0,LSTRE=0,RDWE=0,??=0,??=0 */
  setReg8(PEAR, 0x00U);                 
  /*  System clock initialization */
  /* CLKSEL: PLLSEL=0,PSTP=0,SYSWAI=0,ROAWAI=0,PLLWAI=0,CWAI=0,RTIWAI=0,COPWAI=0 */
  setReg8(CLKSEL, 0x00U);              /* Select clock source from XTAL and set bits in CLKSEL reg. */ 
  /* PLLCTL: CME=1,PLLON=0,AUTO=1,ACQ=1,??=0,PRE=0,PCE=0,SCME=1 */
  setReg8(PLLCTL, 0xB1U);              /* Disable the PLL */ 
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code using property "User code after PE initialization" on the build options tab of the CPU component. !!! ***/

  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm("jmp _Startup");               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

#pragma CODE_SEG DEFAULT
/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S12C32_80)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* Common initialization of the CPU registers */
  /* PUCR: PUPBE=1 */
  setReg8Bits(PUCR, 0x02U);             
  /* PORTB: BIT6=0,BIT5=0,BIT4=0 */
  clrReg8Bits(PORTB, 0x70U);            
  /* DDRB: BIT6=1,BIT5=1,BIT4=1,BIT2=0,BIT1=0,BIT0=0 */
  clrSetReg8Bits(DDRB, 0x07U, 0x70U);   
  /* PIEP: PIEP1=0 */
  clrReg8Bits(PIEP, 0x02U);             
  /* PERP: PERP1=0 */
  clrReg8Bits(PERP, 0x02U);             
  /* DDRP: DDRP1=0 */
  clrReg8Bits(DDRP, 0x02U);             
  /* CRGINT: LOCKIE=0,SCMIE=0 */
  clrReg8Bits(CRGINT, 0x12U);           
  /* VREGCTRL: LVIE=0 */
  clrReg8Bits(VREGCTRL, 0x02U);         
  /* RDRIV: RDPE=0,RDPB=0,RDPA=0 */
  clrReg8Bits(RDRIV, 0x13U);            
  /* RDRAD: RDRAD7=0,RDRAD6=0,RDRAD5=0,RDRAD4=0,RDRAD3=0,RDRAD2=0,RDRAD1=0,RDRAD0=0 */
  setReg8(RDRAD, 0x00U);                
  /* RDRJ: RDRJ7=0,RDRJ6=0 */
  clrReg8Bits(RDRJ, 0xC0U);             
  /* RDRM: RDRM5=0,RDRM4=0,RDRM3=0,RDRM2=0,RDRM1=0,RDRM0=0 */
  clrReg8Bits(RDRM, 0x3FU);             
  /* RDRP: RDRP7=0,RDRP6=0,RDRP5=0,RDRP4=0,RDRP3=0,RDRP2=0,RDRP1=0,RDRP0=0 */
  setReg8(RDRP, 0x00U);                 
  /* RDRS: RDRS3=0,RDRS2=0,RDRS1=0,RDRS0=0 */
  clrReg8Bits(RDRS, 0x0FU);             
  /* RDRT: RDRT7=0,RDRT6=0,RDRT5=0,RDRT4=0,RDRT3=0,RDRT2=0,RDRT1=0,RDRT0=0 */
  setReg8(RDRT, 0x00U);                 
  /* INTCR: IRQEN=0 */
  clrReg8Bits(INTCR, 0x40U);            
  /* ### MC9S12C32_80 "Cpu" init code ... */
  /* ### BitIO "Sensor_A" init code ... */
  /* ### BitIO "Sensor_B" init code ... */
  /* ### BitIO "Sensor_C" init code ... */
  /* ### BitIO "Eve" init code ... */
  /* ### BitIO "Evs" init code ... */
  /* ### BitIO "Interruptor" init code ... */
  /* ### BitIO "SinalFalha" init code ... */
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
