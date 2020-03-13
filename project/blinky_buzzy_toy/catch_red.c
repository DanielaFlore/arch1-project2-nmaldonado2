#include "catch_red.h"
#include "led.h"
#include "buzzer.h"

unsigned char light_speed = 150;

static void state_advance()
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

void catch_red() {
  static char blink_count = 0;
  
  if (++blink_count == light_speed) {
    state_advance();
    blink_count = 0;
  }
}
