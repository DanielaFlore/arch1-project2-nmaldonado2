#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_turn_off() {

  // Set bits for p2 sel2 off.
  P2SEL2 |= (BIT6 | BIT7);
  P2SEL |= BIT7; 
  //P2SEL |= BIT6;
  //P2DIR = BIT6;
}

void buzzer_turn_on() {

  // Set bits for p2 sel2 off.
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7; 
  //P2SEL |= BIT6;
  //P2DIR = BIT6;
}

void buzzer_set_period(short cycles, short mute) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{

  CCR0 = cycles; 
  CCR1 = cycles >> mute;
  
  
  // >> larger number makes it deeper
  // >> larger number makes it quiter. very mute
  // at 10.
  /* one half cycle */
}
/*
void set_sound() {
  static int turned_on = 1;
  if (turned_on) {
    buzzer_turn_off();
    turned_on = 0;
  }
  else {
    buzzer_turn_on();
    turned_on = 1;
  }
}
*/
short frequency(short i){
  if (i == 1) {
    return 6000;
  }
  if (i == 2) {
    return 7000;
  }
  if (i == 3) {
    return 8000;
  }
  if (i == 4) {
    return 7700;
  }
  if (i == 5) {
    return 7850;
  }
  return 22000;
}
short pitch(short i) {
  /*if (i == 1) {
    return 1;
  }
  if (i == 2) {
    return 1;
    }*/
  return 1;
}

void set_sound(char i) {
static int turned_on = 1;
  if (turned_on) {

    set_frequency(frequency(i), pitch(i));
    turned_on = 0;
  }
  else {
    set_frequency(frequency(i), pitch(i));
    turned_on = 1;
  }
}

void set_frequency(short cycles, short mute) {
  CCR0 = cycles; 
  CCR1 = cycles >> mute;
}

/*
void
__interrupt_vec(WDT_VECTOR) WDT(){ 
  static char blink_count = 0;

  //buzzer_init();
  //buzzer_set_period(10000);
  //buzzer_turn_on();
  if (++blink_count >= 25) {
    set_sound();
    blink_count = 0;
  }
}
*/

