#include <msp430.h>
#include "wdInterruptHandler.h"
#include "simon.h"
#include "catch_red.h"
#include "find_frequency.h"
#include "fur_elise.h"

char game_num = 1;



void
__interrupt_vec(WDT_VECTOR) WDT() {	/* 250 interrupts/sec */
  
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
