#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "wdInterruptHandler.h"
#include "led.h"
#include "simon.h"
#include "catch_red.h"
#include "find_frequency.h"

char game_num = 1;


void set_light(char conductor_position, char change_dimness) {
  static char dim_light = 0;
  dim_light = (change_dimness) ? dim_light^1 : dim_light;
  if (dim_light) {
    if (conductor_position % 2 == 0) {

      if (red_on) {
	turn_off_red();
      }
      turn_on_green();
      turn_off_green();
    }
    else {
      if (green_on) {
	turn_off_green();
      }
      turn_on_red();
      turn_off_red();
    }
  }
  else {
    if (conductor_position % 2 == 0) {
      if (red_on) {
	turn_off_red();
      }
      turn_on_green();
    }
    else {
      if (green_on) {
	turn_off_green();
      }
      turn_on_red();
    }
  }
}

void fur_elise_sound(){
  short sound_notes[] = {1,2,1,2,1,3,4,5,6};
  static char conductor = 0;
  static int blink_count = 0;
  
  if (++blink_count < 200) {
    set_light(conductor, ((blink_count == 1)? 1 : 0));
  }
  
  if (blink_count > 200) {
    set_sound(sound_notes[conductor]);
  }
  if (blink_count > 200 && blink_count < 225) {
    set_frequency(1,1);
  }
  if (++blink_count > 225) {
    if (++conductor > 8) {
      conductor = 0;
    }
    blink_count = 0;
    buzzer_turn_on();
  }
}  

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
