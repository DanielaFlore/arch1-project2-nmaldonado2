#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "wdInterruptHandler.h"
#include "led.h"

char game_num = 1;
signed char frequency_btn = -1;
unsigned char light_speed = 150;

char display_pattern();

void fur_elise_sound(){
  short sound_notes[] = {1,2,1,2,1,3,4,5,6};
  static int conductor = 0;
  static int blink_count = 0;
  
  if (++blink_count > 200) {
    set_sound(sound_notes[conductor]);
    //set_sound();
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
  
  /*
  if (++blink_count > 200) {
    set_sound2(1);
    blink_count = 0;
  }
  */
  
  /*
  if (++blink_count > 200){
    if (sound_notes[conductor++] == 1) {
      buzzer_set_period(1000, 1);
    }
    else if (sound_notes[conductor++] == 2){
      high_pitch();
    }
    if (conductor > 2) {
      conductor = 0;
    }
    set_sound();
    blink_green();
    blink_count = 0;
  }
  */
  /*
  if (++blink_count < 50) {
    buzzer_set_period(1000,1);
  }
  if (blink_count > 50) {
    buzzer_set_period(10000, 1);
  }
  if (blink_count >= 150) {
    blink_count = 0;
  }
  */


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
  /*
  else {
    turn_off_red();
    turn_off_green();
    }*/
  buzzer_set_period(rand_frequency, 1);
}

void catch_red() {
  static char blink_count = 0;
  
  if (++blink_count == light_speed) {
    state_advance();
    blink_count = 0;
  }
}

unsigned char add_pattern = 1;
unsigned char curr_pattern = 0;
unsigned char wait_for_pattern = 0;
unsigned char game_pattern[32];

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

char display_pattern() {
  static int blink_count= 0;
  static unsigned char curr_index;
  if (blink_count == 0) {
    turn_off_green();
    turn_off_red();
  }
  blink_count++;
  if (blink_count == 100) {
    red_on = (game_pattern[curr_index]) ? 1 : 0;
    green_on = (red_on) ? 0: 1;
    led_change();
  }
  if (blink_count == 225) {
    blink_count = 0;
    curr_index++;
    turn_off_red();
    turn_off_green();
    if (curr_index > curr_pattern) {
      curr_pattern = 0;
      wait_for_pattern = 1;
      curr_index = 0;
      return 0;
    }
  }
  return 1;
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
   
    //buzzer_turn_off();
    catch_red();
    
  }
  else {
    simon();
  }
}
