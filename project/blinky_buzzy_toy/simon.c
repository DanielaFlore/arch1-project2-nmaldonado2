#include <stdlib.h>
#include <msp430.h>
#include "led.h"
#include "simon.h"
#include "buzzer.h"

unsigned char add_pattern = 1;
unsigned char curr_pattern = 0;
unsigned char wait_for_pattern = 0;
unsigned char game_pattern[32];

static char display_pattern();

static char display_pattern() {
  static int blink_count= 0;
  static unsigned char curr_index;
  if (blink_count == 0) {
    turn_off_green_red();
  }
  blink_count++;
  if (blink_count == 200) {
    red_on = (game_pattern[curr_index]) ? 1 : 0;
    green_on = (red_on) ? 0: 1;
    led_change();
  }
  if (blink_count == 325) {
    blink_count = 0;
    curr_index++;
    turn_off_green_red();
    if (curr_index > curr_pattern) {
      curr_pattern = 0;
      wait_for_pattern = 1;
      curr_index = 0;
      return 0;
    }
  }
  return 1;
}

void simon() {
  buzzer_set_period(0,0);
  static short tick = 0;
 
  static char print_pattern = 0;
  if (tick > 225) {
    tick = 0;
  }
  tick++;
  
  if (add_pattern) {
    //game_pattern[curr_pattern] = feeder[curr_pattern];
    game_pattern[curr_pattern] = tick % 2;
    game_pattern[curr_pattern + 1] = 2;
    print_pattern = 1;
    add_pattern = 0;
  }
  
  if (print_pattern) {
    print_pattern = display_pattern();
  }
  if (wait_for_pattern) {

  }
}
