#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void turn_green_on();
void turn_green_off();
void turn_on_off_green();
void turn_red_on();

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
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

char turn_on_green_forever(){
  //if(green_on){
    //return 0;

    //}
  green_on = 1;
  red_on = 0;
  return 1;
}

void blink_green() {
  static int blink_twice = 0;

  if (blink_twice == 0 || blink_twice == 2) {
    red_on = 1;
    blink_twice++;
  }
  else if (blink_twice == 1 || blink_twice == 3){
    red_on = 0;
    blink_twice++;
  }
  else if(blink_twice == 4){
    green_on = 1;
    blink_twice++;
  }
  else {
    green_on = 0;
   
    blink_twice = 0;
  }

  led_change();
}

void green_blink(){
  static char on = 0;
  if(!green_on){
    green_on = 1;
  }
  
  if(!on){
    red_on = 1;
    led_change();
    on = 1;
    return;
  }
  
  red_on = 0;
  led_change();
  on = 0;
}

void turn_green_on() {
  red_on = 1;
  green_on = 0;
  led_change();
}

void turn_on_off_green() {
  static char on = 0;
  if (!on) {
    turn_green_on();
    on = 1;
  }
  else {
    turn_red_on();
    on = 0;
  }
}

void turn_green_off() {
  red_on = 0;
  led_change();
}

void turn_red_on() {
  green_on = 1;
  red_on = 0;
  led_change();
}

turn_off() {
  green_on = red_on = 0;
  led_change();
}

void turn_red_off() {
  green_on = 0;
  led_change();
}

void turn_green_and_red_on() {
  green_on = red_on = 1;
  led_change();
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
  //static enum {R=0, G=1} color = G;
  /*
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = turn_on_green_forever(); color = R; break;
  }
  */
  // changed = turn_on_green_forever();
 
  //led_changed = changed;
  //led_update();
}
