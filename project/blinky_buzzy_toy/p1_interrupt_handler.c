#include <msp430.h>
#include "buttons.h"
#include "wdInterruptHandler.h"

void frequency_recovery() {
  if (P2IFG & BTN1 && frequency_btn == 1) {
    P2IFG &= ~BIT0;
    frequency_btn = -1;
  }
  // BTN 2 pressed.
  else if ((P2IFG & BTN2) && frequency_btn == 2) {
    P2IFG &= ~BIT1;
    frequency_btn = -1;
  }
  else if ((P2IFG & BTN3) && frequency_btn == 3) {
    P2IFG &= ~BIT2;
    frequency_btn = -1;
  }
  else if ((P2IFG & BTN4) && frequency_btn == 4) {
    P2IFG &= ~BIT3;
    frequency_btn = -1;
  }
  
}

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){

  // only button 1 is pressed.
  if ((P2IFG & BTN1) && game_num == 1) {
    P2IFG &= ~BIT0;
    game_num = 2;
    
  }

  if (game_num == 2) {
    frequency_recovery();
  }
  //if (P2IFG & BUTTONS) {	      /* did a button cause this interrupt? */
  //P2IFG &= ~BUTTONS;		      /* clear pending sw interrupts */
    //buttons_interrupt_handler();	/* single handler for all switches */
    //}
}

