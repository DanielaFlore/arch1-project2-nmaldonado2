#include <msp430.h>
#include "buttons.h"
#include "wdInterruptHandler.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"
//#include "game_one_two_interrupt_handler.s"

extern void game_three_interrupt_handler();

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
}

void game_four_interrupt_handler() {
  if ((P2IN & BUTTONS) == (~BTN3 & BUTTONS)) {
    game_num = 1;
    curr_pattern = 0;
    add_pattern = 1;
    wait_for_pattern = 0;
  }
  else if (wait_for_pattern) {
    if ((P2IN & 0xf) == 0x7) {
      turn_on_red();
    }
    else if ((P2IN & 0xf) == 0xe) {
      turn_on_green();
    }
    else {
      if (green_on) {

	// If curr_pattern == 0, then should press
	// green.
	if (game_pattern[curr_pattern] == 0) {
	  curr_pattern++;
	  if (curr_pattern >= 31) {
	    curr_pattern = 0;
	    wait_for_pattern = 0;
	    add_pattern = 1;
	  }
	  else if (game_pattern[curr_pattern] == 2) {
	    add_pattern = 1;
	    wait_for_pattern = 0;
	  }
	}
	else {
	  curr_pattern = 0;
	  wait_for_pattern = 0;
	  add_pattern = 1;
	}
      }

      else if (red_on) {
	// If curr_pattern == 1, then should
	// press red.
	if (game_pattern[curr_pattern] == 1) {
	  curr_pattern++;
	  if (curr_pattern >= 31) {
	    curr_pattern = 0;
	    wait_for_pattern = 0;
	    add_pattern = 1;
	  }
	  else if (game_pattern[curr_pattern] == 2) {
	    add_pattern = 1;
	    wait_for_pattern = 0;
	  }
	}
	else {
	  curr_pattern = 0;
	  wait_for_pattern = 0;
	  add_pattern = 1;
	}  
      }
    
      turn_off_green();
      turn_off_red();
    }   
  }
}
/*
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
*/
void game_one_interrupt_handler() {
  if ((P2IN & BIT0) == 0) {
    game_num = 2;
  }
}

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2() {
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
    else {
      game_four_interrupt_handler();
    }
    buttons_interrupt_handler();
  }
}
