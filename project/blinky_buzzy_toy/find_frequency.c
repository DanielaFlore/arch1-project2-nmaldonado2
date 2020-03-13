#include "find_frequency.h"
#include "buzzer.h"

signed char frequency_btn = -1;

void find_frequency() {
  static int tick = 0;
  static int rand_frequency = 0;
  static char light_on = 0;
  
  if (tick > 440) {
    tick = 1;
  }
  else {
    tick++;
  }
  
  if (frequency_btn == -1) {
    //turn_on_green();
    rand_frequency = (tick % (33000 + 1 - 500)) + 500;
    frequency_btn = (tick % (3 + 1 - 1)) + 1;
    //frequency_btn = 0xe;
    
    switch (frequency_btn) {
    case 1:
      frequency_btn = 0xe;
      break;
    case 2:
      frequency_btn = 0xd;
      break;
    case 3:
      frequency_btn = 0xb;
      break;
    }
    
  }
  buzzer_set_period(rand_frequency, 1);
}
