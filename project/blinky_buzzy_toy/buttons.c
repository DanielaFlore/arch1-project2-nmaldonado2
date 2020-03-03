#include <msp430.h>
#include "buttons.h"
#include "led.h"

char button_state_down, button_state_changed; /* effectively boolean */

static char 
buttons_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & BUTTONS);	/* if switch up, sense down */
  P2IES &= (p2val | ~BUTTONS);	/* if switch down, sense up */
  return p2val;
}

void 
buttons_init()			/* setup switch */
{
  P2OUT |= BUTTONS;
  
  P2REN = BUTTONS;		/* enables resistors for switches */
  P2IE |= BUTTONS;		/* enable interrupts from switches */
  P2OUT |= BUTTONS;		/* pull-ups for switches */
  P2DIR &= ~BUTTONS;		/* set switches' bits for input */
  buttons_update_interrupt_sense();
  led_update();
}

void
buttons_interrupt_handler()
{
  char p1val = buttons_update_interrupt_sense();
  button_state_down = (p1val & BTN1) ? 0 : 1; /* 0 when SW1 is up */
  button_state_changed = 1;
}
