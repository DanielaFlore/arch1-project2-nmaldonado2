// Nichole Maldonado
// This file contains the find_frequency game
// which randomly generates a frequency and
// a matching button that maps to the frequency.
// When this button is pressed,the frequency will
// change.

#include "find_frequency.h"
#include "buzzer.h"

signed char frequency_btn = -1;

/*
 * Function that generates a random frequency
 * and maps a button(1 - 3) to that frequency.
 * Input: None.
 * Output: None.
 */
void find_frequency() {
  static int tick = 0;
  static int rand_frequency = 0;

  // tick can only reach 440 before being reset
  // to 0.
  if (tick > 440) {
    tick = 1;
  }
  else {
    tick++;
  }

  // If frequency_btn is -1, then create a new
  // random frequency and assign it a random
  // button mapping.
  if (frequency_btn == -1) {
    rand_frequency = (tick % (33000 + 1 - 500)) + 500;
    frequency_btn = (tick % (3 + 1 - 1)) + 1;  
  }
  buzzer_set_period(rand_frequency, 1);
}
