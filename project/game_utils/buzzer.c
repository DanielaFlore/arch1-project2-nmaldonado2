// Nichole Maldonado and Previous Commits
// This file provides functions to initialize
// the four buttons, and set the sound by
// adjusting the cycles and mute factor.

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

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
    return 2637;
  }

  // Note E flat
  if (note_num == 2) {
    return 2489;
  }

  // Note B
  if (note_num == 3) {
    return 1975;
  }

  // Note D
  if (note_num == 4) {
    return 2349;
  }

  // Note C
  if (note_num == 5) {
    return 2093;
  }

  // Note A
  return 1760;
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
