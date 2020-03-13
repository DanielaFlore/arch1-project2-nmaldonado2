#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buttons.h"
#include "simon.h"
#include "find_frequency.h"

char game_num = 1;

//extern void game_three_interrupt_handler();

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
	// If curr_pattern == 0, then should press
	// green.
      if ((green_on && game_pattern[curr_pattern] == 0) || (red_on && game_pattern[curr_pattern] == 1)) {
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
    
      turn_off_green();
      turn_off_red();
    }   
  }
}

void game_one_interrupt_handler() {
  if ((P2IN & BIT0) == 0) {
    game_num = 2;
  }
}

