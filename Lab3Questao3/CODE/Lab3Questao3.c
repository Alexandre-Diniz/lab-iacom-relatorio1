/** ###################################################################
**     Filename  : Lab3Questao3.c
**     Project   : Lab3Questao3
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
/* MODULE Lab3Questao3 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "DirecaoDireitaOut.h"
#include "DirecaoEsquerdaOut.h"
#include "DirecaoDireitaIn.h"
#include "DirecaoEsquerdaIn.h"
#include "AumentarVelocidade.h"
#include "DiminuirVelocidade.h"
#include "LigarParaBrisa.h"
#include "VelocidadeParaBrisa.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
       
void main(void)
{
  /* Write your local variable definition here */


  int start = 1, velocidade=0;
  bool direcaoDireitaIn=0, direcaoEsquerdaIn=0, aumentarVelocidade=0, diminuirVelocidade=0, ligarParaBrisa=0;               

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */



do {

	/* Direção */
  direcaoDireitaIn = DirecaoDireitaIn_GetVal();
  direcaoEsquerdaIn = DirecaoEsquerdaIn_GetVal();
  DirecaoDireitaOut_PutVal(direcaoDireitaIn);
  DirecaoEsquerdaOut_PutVal(direcaoEsquerdaIn);
  /* Direção */
  
  ligarParaBrisa = LigarParaBrisa_GetVal();
  /* Aumentar velocidade para-brisa */
  if(ligarParaBrisa){
    // registra o valor passado
    aumentarVelocidade = AumentarVelocidade_GetVal();
    // detecta mudanca na borda de subida
    if(!aumentarVelocidade && AumentarVelocidade_GetVal()){
      if(velocidade>=0 && velocidade<3){// pode aumentar a velocidade
        velocidade = velocidade + 1;
      } // a segunda condicao do if impede que a velocidade aumenete acima do nivel 3
    }
  }
  /* Aumentar velocidade para-brisa */
  
  /* Diminuir velocidade para-brisa */
  if(ligarParaBrisa){
    // registra o valor passado
    diminuirVelocidade = DiminuirVelocidade_GetVal();
    // detecta mudanca na borda de subida
    if(!diminuirVelocidade && DiminuirVelocidade_GetVal()){
      if(velocidade>0 && velocidade<=3){// pode aumentar a velocidade
        velocidade = velocidade - 1;
      } // a segunda condicao do if impede que a velocidade diminua abaixo do nivel 0
    }
  }
  /* Diminuir velocidade para-brisa */
  
  /* Setar a velocidade do para-brisa */
  if(ligarParaBrisa){
    VelocidadeParaBrisa_Enable();
    if(velocidade==0){
      VelocidadeParaBrisa_SetDutyMS(500);
    } else if(velocidade==1){
      VelocidadeParaBrisa_SetDutyMS(250);
    } else if(velocidade==2){
      VelocidadeParaBrisa_SetDutyMS(125);
    } else if(velocidade==3){
      VelocidadeParaBrisa_SetDutyMS(62);
    } else {
      VelocidadeParaBrisa_Disable();
    }
  } else{
    VelocidadeParaBrisa_Disable();
  }
  /* Setar a velocidade do para-brisa */
	   

}while (start);

  
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END Lab3Questao3 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
