// Nichole Maldonado
// This file contains the main function
// that has 250 interrupts/sec and calls the
// corresponding game function based on the
// game_num.

#include <msp430.h>
#include "state_machines.h"
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
  switch(game_num) {
  case 1:
    fur_elise_sound();
    break;
  case 2:
    find_frequency();
    break;
  case 3:
    catch_red();
    break;
  default:
    simon();
    break;
  }
}
