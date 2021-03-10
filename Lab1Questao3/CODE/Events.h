/** ###################################################################
**     Filename  : Events.h
**     Project   : Lab1Questao3
**     Processor : MC9S12C128CFU16
**     Component : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 08/11/2020, 11:26
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "DirecaoDireitaOut.h"
#include "DirecaoEsquerdaOut.h"
#include "DirecaoDireitaIn.h"
#include "DirecaoEsquerdaIn.h"
#include "AumentarVelocidade.h"
#include "DiminuirVelocidade.h"
#include "LigarParaBrisa.h"
#include "VelocidadeParaBrisa.h"

#pragma CODE_SEG DEFAULT


void EInt1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* END Events */
#endif /* __Events_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
