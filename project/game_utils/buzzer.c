// Nichole Maldonado and Previous Commits
// This file provides functions to initialize
// the four buttons, and set the sound by
// adjusting the cycles and mute factor.

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

#define NOTE_E 3033
#define NOTE_E_FLAT 3214
#define NOTE_B 4049
#define NOTE_D 3405
#define NOTE_C 3822
#define NOTE_A 4545

static short cycles(unsigned char note_num);

/*
 * Function that initializes the buzzer to
 * be used throughout the program.
 * Input: None
 * Output: None
 */
void buzzer_init()
{
    
  // Direct timer A output "TA0.1" to P2.6.  
  // According to table 21 from data sheet:
  // P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
  // P2SEL.6 must be 1
  // Also: P2.6 direction must be output
  // Used to drive speaker.
  timerAUpmode();
  
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7; 
  P2SEL |= BIT6;

  // Enable output to speaker.
  P2DIR = BIT6;
}

/*
 * Function that sets the buzzer period where
 * the buzzer clock is at 2MHz (period of 1k
 * results in 2kHz tone).
 * Input: The number of cycles and the mute
 *        which represents the number of bits
 *        the cycle is shifted.
 * Output: None.
 */
void buzzer_set_period(short cycles, char mute) 
{

  CCR0 = cycles; 
  CCR1 = cycles >> mute;
}

/*
 * Function that assigns the number of cycles for 
 * Fur Elise based on the note number.
 * Input: The note number ranging from 1 - 6.
 * Output: the number of cycles
 */
static short cycles(unsigned char note_num)
{

  // Note E
  if (note_num == 1) {
    return NOTE_E;
  }

  // Note E flat
  if (note_num == 2) {
    return NOTE_E_FLAT;
  }

  // Note B
  if (note_num == 3) {
    return NOTE_B;
  }

  // Note D
  if (note_num == 4) {
    return NOTE_D;
  }

  // Note C
  if (note_num == 5) {
    return NOTE_C;
  }

  // Note A
  return NOTE_A;
}

/*
 * Function that sets the sound based on
 * the note number passed in.
 * Input: The note number ranging from 1 - 6.
 * Output: None.
 */
void set_sound(unsigned char i)
{

  // Finds note based on cycles and sets it.
  buzzer_set_period(cycles(i), 1);
}
