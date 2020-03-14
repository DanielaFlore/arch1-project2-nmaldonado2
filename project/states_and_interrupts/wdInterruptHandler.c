// Nichole Maldonado
// This file contains the main function
// that has 250 interrupts/sec and calls the
// corresponding game function based on the
// game_num.

#include <msp430.h>
#include "stateMachines.h"
#include "simon.h"
#include "catch_red.h"
#include "find_frequency.h"
#include "fur_elise.h"

/*
 * Function that moves based on the clock
 * and has 250 interrupts/sec. Based on the
 * game_num, the corresponding state/game
 * is played.
 * Input: None.
 * Output: None.
 */
void __interrupt_vec(WDT_VECTOR) WDT()
{
  // Plays game based on game_num/state.
  if (game_num == 1) {
    fur_elise_sound();
  }
  else if (game_num == 2) {
    find_frequency();
  }
  else if (game_num == 3) {
    catch_red();
  }
  else {
    simon();
  }
}
