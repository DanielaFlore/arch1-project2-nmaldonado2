// Nichole Maldonado
// This file contains the find_frequency game
// which randomly generates a frequency,
// based on the number of cycles, and
// a matching button that maps to the frequency.
// When this button is pressed,the frequency will
// change.

#include <msp430.h>
#include "find_frequency.h"
#include "buzzer.h"
#include "buttons.h"

signed char frequency_btn = -1;

/*
 * Function that generates a random frequency,
 * bazed on a randomly generated number of
 * cycles, and maps a button(1 - 3) to that 
 * frequency.
 * Input: None.
 * Output: None.
 */
void find_frequency()
{
  static int tick = 0;
  static int rand_num_cycles = 0;

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

    // Range from [500, 15000]
    rand_num_cycles = (tick % 15000) + 500;

    // Range from [3, 1]
    frequency_btn = (tick % 3) + 1;

    // Maps the frequency button from 1 - 3
    // to the actual button pressed representation
    // with the bits.
    switch (frequency_btn) {
    case 1:
      frequency_btn = ~BTN1 & BUTTONS;
      break;
    case 2:
      frequency_btn = ~BTN2 & BUTTONS;
      break;
    case 3:
      frequency_btn = ~BTN3 & BUTTONS;
      break;
    }
  }
  buzzer_set_period(rand_num_cycles, 1);
}
