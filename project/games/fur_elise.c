#include "fur_elise.h"
#include "buzzer.h"
#include "led.h"

static void set_light(char conductor_position, char change_dimness) {
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
    buzzer_set_period(1,1);
  }
  if (++blink_count > 225) {
    if (++conductor > 8) {
      conductor = 0;
    }
    blink_count = 0;
  }
}  
