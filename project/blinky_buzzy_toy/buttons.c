#include <msp430.h>
#include "buttons.h"
#include "led.h"

char button_state_down, button_state_changed; /* effectively boolean */

static void
buttons_update_interrupt_sense()
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

void 
buttons_init()			/* setup switch */
{
  P2OUT |= BUTTONS;
  
  P2REN |= BUTTONS;		/* enables resistors for switches */
  P2IE = BUTTONS;		/* enable interrupts from switches */
  P2OUT |= BUTTONS;		/* pull-ups for switches */
  P2DIR &= ~BUTTONS;		/* set switches' bits for input */
  buttons_update_interrupt_sense();
  led_update();
}

void
buttons_interrupt_handler()
{
  buttons_update_interrupt_sense();
  // If P2IN.x == 0, then button was pressed.
  button_state_down = (P2IN & BUTTONS) ? 1 : 0;
}
