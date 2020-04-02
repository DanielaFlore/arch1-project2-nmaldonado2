// Nichole Maldonado
// This file contains the interrupt handlers called
// that advance the state if the designated button
// is pressed or performs a game/ state specific
// functionality otherwise.

#include <msp430.h>
#include "led.h"
#include "buttons.h"
#include "simon.h"
#include "buzzer.h"

char game_num = 1;

/*
 * Interrupt handler for Simon that moves to 
 * the next state if BTN3 is pressed or
 * identifies if the user is currently entering
 * the correct pattern. If not, the game is
 * restarted.
 * Input: None
 * Output: None
 */
void game_four_interrupt_handler()
{

  // If BTN3 is pressed, got to next state,
  // or namely state 1.
  if ((P2IN & BUTTONS) == (~BTN3 & BUTTONS)) {
    game_num = 1;
    curr_pattern = 0;
    add_pattern = 1;
    wait_for_pattern = 0;
  }

  // If waiting_for pattern, evaluate.
  else if (wait_for_pattern) {


    // If BTN4 is pressed, turn on red.
    if ((P2IN & BUTTONS) == (~BTN4 & BUTTONS)) {
      turn_on_red();
      buzzer_set_period(900, 2);
    }

    // If BTN1 is pressed, turn on green.
    else if ((P2IN & BUTTONS) == (~BTN1 & BUTTONS)) {
      turn_on_green();
      buzzer_set_period(1200, 1);
    }

    // Otherwise, if button is released, analyze.
    else {
      
      // If led flag matches its associated
      // pattern stored, then evaluate.
      if ((green_on && game_pattern[curr_pattern] == 0) || (red_on && game_pattern[curr_pattern] == 1)) {
	curr_pattern++;

	// Max of 32 possible patterns, so
	// reset.
	if (curr_pattern >= 31) {
	  curr_pattern = 0;
	  wait_for_pattern = 0;
          add_pattern = 1;
	}

	// 2 Marks the end of the pattern
	// so add a new pattern.
	else if (game_pattern[curr_pattern] == 2) {
          add_pattern = 1;
	  wait_for_pattern = 0;
	}
      }

      // Otherwise, invalid pattern entered
      // so start from the beginning.
      else {
        curr_pattern = 0;
        wait_for_pattern = 0;
        add_pattern = 1;
      }
      
      buzzer_set_period(0,0);
      turn_off_green_red();
    }   
  }
}

/*
 * Interrupt handler for Fur Elise
 * that transitions to the next state
 * if the first button is pressed.
 * Input: None
 * Output: None
 */
void game_one_interrupt_handler()
{
  if ((P2IN & BIT0) == 0) {
    game_num = 2;
  }
}

// DEPRECATED. The following code can be
// found in the assembly file
// games_two_three_interrupt_handlers.s

// Handler for game 2 which determines if
// user selected the correct button that
// maps to the random frequency.
/*
void game_two_interrupt_handler()
{
  switch (P2IN & BUTTONS) {
  case (~BTN4 & BUTTONS):
    game_num = 3;
    break;
  

  // If no buttons are pressed, turn off all leds.
  case BUTTONS:
    turn_off_green_red();
    break;
  default:

    // NOTE: If, else used since frequency_btn
    // is not a constant value and cannot be a case.
    // If the frequency_btn matches the button
    // pressed turn on green and set frequency_btn
    // to -1.

    if ((P2IN & BUTTONS) == frequency_btn) {
      turn_on_green();
      frequency_btn = -1;
    }

    // Otherwise, turn on red.
    else {
      turn_on_red.
    }
  }    
}
*/

 // DEPRECATED: The following code is implemented
 // in the assembly file
 // games_two_three_interrupt_handlers.s

 // Handler for catch red which
 // makes the lights toggle faster
 // if the red light and BTN4 are pressed
 // simultaneously.
 /*
void game_three_interrupt_handler()
{

  // If BTN2 pressed, go to next state.
  if ((P2IN & BUTTONS) == (~BTN2 & BUTTONS)) {
    game_num = 4;
  }
  
  if ((P2IN & BUTTONS) == (~BTN4 & BUTTONS)) {

    // If red is on, go faster.
    if (red_on) {
      light_speed -= 5;
    }

    // Reset light_speed if light_speed is too
    // fast or red is not on.
    if (!red_on || light_speed <= 15) {
      light_speed = 150;
    }
  }
}

*/
