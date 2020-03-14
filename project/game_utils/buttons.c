// Nichole Maldonado and Previous commits
// This file includes functions to set
// the buttons by using the pull up_resitors.
// If a button is pressed, the IES is set to
// sense an up transition, and vice versa.

#include <msp430.h>
#include "buttons.h"

/*
 * This function sets the IES to sense a
 * transition from high to low, if the previous
 * transition was from low to high, and vice
 * versa.
 * Input: None
 * Output: None
 */
void buttons_update_interrupt_sense()
{
  // Button is up if bit == 1
  // So if button is up, set P2IES to 1, to
  // prepare for a high to low transition.
  // (when button is pressed).
  P2IES |= (P2IN & BUTTONS);

  // Button is down if bit == 0
  // So if button is down, set P2IES to 0, to
  // prepare for a low to high transition.
  // (when button is released).
  P2IES &= (P2IN | ~BUTTONS); 
}

void buttons_init()
{
  P2OUT |= BUTTONS;
  
  // Enable resistors for buttons
  P2REN |= BUTTONS;

  // Enable interrupts from buttons.
  P2IE = BUTTONS;

  // Enable pull-ups for buttons.
  P2OUT |= BUTTONS;

  // Close P1DIR transmission gate for buttons.
  P2DIR &= ~BUTTONS;
  
  buttons_update_interrupt_sense();
}
