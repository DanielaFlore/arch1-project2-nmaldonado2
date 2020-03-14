// Nichole Maldonado
// This file determines which functions to
// to call to handle the interrupt based
// on the game number.

#include <msp430.h>
#include "buttons.h"
#include "stateMachines.h"

/*
 * Function that calls the corresponding
 * interrupt handler based on the game_num.
 * Input: None.
 * Outpu: None.
 */
void __interrupt_vec(PORT2_VECTOR) Port_2()
{

  // Handle interrupt based on button.
  if (P2IFG & BUTTONS) {

    // Clear P2IFG for next interrupt interpretation.
    P2IFG &= ~BUTTONS;

    // Fur elise interrupt handler.
    if (game_num == 1) {
      game_one_interrupt_handler();
    }

    // Find frequency interrupt handler.
    else if (game_num == 2) {
      game_two_interrupt_handler();
    }

    // Catch red interrupt handler.
    else if (game_num == 3) {
      game_three_interrupt_handler();
    }

    // Simon interrupt handler.
    else {
      game_four_interrupt_handler();
    }

    // Update IES.
    buttons_update_interrupt_sense();
  }
}
