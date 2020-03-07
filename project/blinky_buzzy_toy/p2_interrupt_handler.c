#include <msp430.h>
#include "buttons.h"
#include "wdInterruptHandler.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"

void frequency_recovery() {
  if ((P2IN & BUTTONS) == 0x7) {
    game_num = 3;
  }
  else if ((P2IN & 0xf) == 0xf) {
    turn_off_green();
    turn_off_red();
  }
  else {
    if ((P2IN & 0xf) == frequency_btn) {
      turn_on_green();
      frequency_btn = -1;
    }
    else {
      turn_on_red();
    }
  }
  /*
  if ((P2IN & BIT0) == 0) {
    //turn_on_red();
    //turn_off_green();
  }
  else if ((P2IN & BIT1) == 0) {
    //turn_on_red();
  }
  else if ((P2IN & BIT2) == 0) {
    //turn_on_red();
  }
  else {
    //turn_off_green();
    //turn_off_red();
  }
  */
  /*
  if (P2IFG & BIT3) {
    P2IFG &= ~BIT3;
    //turn_on_red();
    buzzer_turn_off();
    game_num = 3;
  }
  else if ((P2IFG & BTN1) && frequency_btn == 1) {
    P2IFG &= ~BTN1;
    frequency_btn = -1;
    
  }
  // BTN 2 pressed.
  else if ((P2IFG & BTN2) && frequency_btn == 2) {
    P2IFG &= ~BTN2;
    frequency_btn = -1;
  }
  else if ((P2IFG & BTN3) && frequency_btn == 3) {
    P2IFG &= ~BTN3;
    frequency_btn = -1;
  }
  else {
    turn_on_red();
    P2IFG &= ~BUTTONS;
  }
  */
}

void game_three_interrupt_handler() {
  if ((P2IN & BUTTONS) == (~BTN2 & BUTTONS)) {
    game_num = 4;
  }
  else if ((P2IN & BUTTONS) == (~BTN4 & BUTTONS)) {
    if (red_on) {
      light_speed -= 5;
    }
    if (!red_on || light_speed <= 15) {
      light_speed = 150;
    }
  }
}

void game_one_interrupt_handler() {
  if ((P2IN & BIT0) == 0) {
    game_num = 2;
  }
}

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2() {
  //buttons_interrupt_handler();
  /*
  if (game_num == 1) {
    game_one_interrupt_handler();
  }
  */
  if (P2IFG & BUTTONS) {
    P2IFG &= ~BUTTONS;
    if (game_num == 1) {
      game_one_interrupt_handler();
    }
    else if (game_num == 2) {
      frequency_recovery();
    }
    else if (game_num == 3) {
      game_three_interrupt_handler();
    }
    buttons_interrupt_handler();
  }
  /*
  if (button_state_down) {
    turn_on_red();
    turn_off_green();
  }
  else {
    turn_on_green();
    turn_off_red();
  }
  */
  /*
  else if (game_num == 2) {
    frequency_recovery();
  }
  */
  //enableWDTInterrupts();
  //turn_off_green();
  // only button 1 is pressed.
  /*
  if ((P2IFG & BTN1) && game_num == 1) {
    P2IFG &= ~BIT0;  
    game_num = 2;
    return;
  }
  */

  // If the game number is 2 and the fourth
  // button has not been pressed.
  /*
  if (~(P2IFG & BIT3) == 0 && game_num == 2) {
    frequency_recovery();
    return;
  }
  if (P2IFG & BIT3) {
    turn_red_on();
    return;
  }
  if ((P2IFG & BIT3) && game_num == 2) {
    P2IFG &= ~BTN4;
    buzzer_turn_off();
    game_num = 3;
    
  }
  */
}
