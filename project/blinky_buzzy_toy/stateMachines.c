#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void blink_green() {
  green_on ^= 1;
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

void state_advance()
{ 
  if (!red_on){
    buzzer_set_period(1000, 1);
    red_on = 1;
    green_on = 0;
    led_change();
  }
  else {
    buzzer_set_period(9000, 1);
    green_on = 1;
    red_on = 0;
    led_change();
  }
}
