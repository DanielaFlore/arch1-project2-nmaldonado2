#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  /*
  if (++blink_count == 250) {
    state_advance();
    blink_count = 0;
  }
  */
  
  //if(++blink_count >= 125){
  //blink_green();
  //blink_count = 0;
  //}

  // dim light

  /*
  if (++blink_count >= 2){
    green_blink();
    green_blink();
    green_blink();
    green_blink();
    blink_count = 0;
  }
  */
  
  //state_advance();
  //while(++blink_count < 500);
  //blink_count = 0;
  //state_advance();
  //while(++blink_count < 500);
  //state_advance();
}

void button_flash() {
  
  int i = 0;

  /*
  while (1) {
    while ((P2IN & 1) == 0) {
      turn_green_on();
    }
    while ((P2IN & 1) != 0) {
      turn_red_on();
    }
  }
  
  */
  /*
  while (1) {
    while ((P2IN & 1) == 0) {
      turn_green_on();
    }
    turn_green_off();
  }
  */

  while (1) {
    while (((P2IN & 1) == 0) && ((P2IN & 8) == 0)) {
      turn_green_and_red_on();
    }

    while ((P2IN & 1) == 0 && (P2IN & 8) != 0) {
      turn_green_on();
    }

    while ((P2IN & 1) != 0 && (P2IN & 8) == 0) {
      turn_red_on();
    }
    while ((P2IN & 1) != 0 && (P2IN & 8) != 0) {
      turn_off();
    }
  }
  
  /*
  else if ((P2IN & 2) ){
    turn_red_on();
  }
  */
  /*
  if ((P2IN & 2) == 0) {
    turn_green_on();
    
  }
  else {
    turn_red_on();
  }
  */
}

/*
void button_init() {
  P2DIR |= 3;
  P2REN &= 3;
}
*/

void button_init()
{
  // Open transmission gate for b0.
  //P2DIR |= 1;		// bits attached to leds are output
  //P2REN &= 1;
  
  P2OUT |= 9;
  
  P2REN |= 9;		/* enables resistors for switches */
  P2IE = 9;		/* enable interrupts from switches */
  P2OUT |= 9;		/* pull-ups for switches */
  P2DIR &= ~9;		/* set switches' bits for input */

}

/*
void led_change()
{
    // Turns on bits
    // if red on then obooooooo1
    // if green on then ob01000000
    char ledFlags = redVal[red_on] | greenVal[green_on];

    // 
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds

    
    P1OUT |= ledFlags;		     // set bit for on leds
   
}*/
