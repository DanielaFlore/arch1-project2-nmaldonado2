// Nichole Maldonado
// File that contians the functions for simon
// which shows a pattern of lights and adds
// a pattern to game_pattern if add_pattern
// is set to true. Note that only 32 game patterns
// can be reached.

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

/*
 * Function that prints the simon pattern and
 * returns 1, if more of the pattern still
 * needs to be printed or 0 if the pattern's
 * printing is done.
 * Input: None
 * Output: 1 to continue printing the pattern,
 *         or 0 if the pattern is done printing.
 */
static char display_pattern()
{

  static int blink_count= 0;
  static unsigned char curr_index = 0;

  if (blink_count == 0) {
    buzzer_set_period(0, 0);
    turn_off_green_red();
  }
  blink_count++;

  // If the game_pattern is 1, then turn red on
  // otherwise, turn green on.
  if (blink_count == 200) {
    red_on = (game_pattern[curr_index]) ? 1 : 0;
    green_on = (red_on) ? 0: 1;
    led_change();
    
    // Set buzzers
    if (red_on) {
      buzzer_set_period(900, 2);
    }
    else {
      buzzer_set_period(1200, 1);
    }
  }

  // If blink_count is 325, then
  // reset the blink_count and turn off
  // the leds.
  else if (blink_count == 325) {
    blink_count = 0;
    curr_index++;

    buzzer_set_period(0, 0);
    turn_off_green_red();

    // If the entire pattern has been printed,
    // set wait_for_pattern to be true. 
    if (curr_index > curr_pattern) {
      curr_pattern = 0;
      wait_for_pattern = 1;
      curr_index = 0;
      return 0;
    }
  }
  return 1;
}

void simon()
{

  // Mute the buzzer.
  static short tick = 0;
  static char print_pattern = 0;

  // reset tick greater than 225.
  if (tick > 225) {
    tick = 0;
  }
  tick++;

  // If add_pattern is true, the generate a
  // new pattern (either green or red)
  // and append it to the game pattern.
  if (add_pattern) {

    // If 1, then red light on.
    // If 0, then green light on.
    game_pattern[curr_pattern] = tick % 2;

    // 2 marks the end of the pattern.
    game_pattern[curr_pattern + 1] = 2;
    print_pattern = 1;
    add_pattern = 0;
  }

  // Continue to print pattern as long as
  // display pattern returns a 1.
  if (print_pattern) {
    print_pattern = display_pattern();
  }
}
