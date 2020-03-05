#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "wdInterruptHandler.h"

char game_num = 1;
signed char frequency_btn = -1;

void high_pitch() {
  buzzer_set_period(1000000, 1);
}

void fur_elise_sound(){
  short sound_notes[] = {1,2,1,2,1,3,4,5,6};
  static int conductor = 0;
  static int blink_count = 0;
  
  if (++blink_count > 200) {
    set_sound2(sound_notes[conductor]);
    //set_sound();
  }
  if (blink_count > 200 && blink_count < 225) {
    buzzer_turn_off();
  }
  if (++blink_count > 225) {
    if (++conductor > 8) {
      conductor = 0;
    }
    blink_count = 0;
    buzzer_turn_on();
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
}

void find_frequency() {
  static int tick = 0;
  static rand_frequency = 0;
  static char light_on = 0;
  
  if (tick > 440) {
    tick = 1;
  }
  else {
    tick++;
  }
  
  if (frequency_btn == -1) {
    turn_on_green();
    rand_frequency = (tick % (33000 + 1 - 500)) + 500;
    frequency_btn = (tick % (3 + 1 - 1)) + 1;
  }
  else {
    turn_off_red();
    turn_off_green();
  }
  buzzer_set_period(rand_frequency, 1);
}

void catch_red(){

}

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  
  if (game_num == 1) {
    fur_elise_sound();
  }
  else if (game_num == 2) {
    find_frequency();
  }
  else if (game_num == 3) {
    catch_red();
  }
}

void button_init()
{
  // Open transmission gate for b0.
  //P2DIR |= 1;		// bits attached to leds are output
  //P2REN &= 1;
  
  P2OUT |= 9;
  
  P2REN |= 9;		/* enables resistors for switches */
  P2IE = 9;		/* enable interrupts from switches */
  P2OUT |= 9;		/* pull-ups for switches */
  P2DIR &= ~9;		/* set switches' bits for input */

}
