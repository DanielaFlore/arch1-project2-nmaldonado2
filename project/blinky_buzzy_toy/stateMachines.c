#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void blink_green() {
  green_on ^= 1;
  led_change();
}

void turn_on_green() {
  green_on = 1;
  red_on = 0;
  led_change();
}

void turn_on_red() {
  red_on = 1;
  green_on = 0;
  led_change();
}

void turn_off_green() {
  green_on = 0;
  led_change();
}

void turn_off_red() {
  red_on = 0;
  led_change();
}

void turn_off_green_red() {
  red_on = green_on = 0;
  led_change();
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  
  if (!red_on){
    red_on = 1;
    green_on = 0;
    led_change();
  }
  else {
    green_on = 1;
    red_on = 0;
    led_change();
  }
}
