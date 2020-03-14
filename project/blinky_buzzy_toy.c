// Nichole Maldonado
// This file holds the main function of the
// program that sets the clocks and game utils.
// The WDTInterrupts are then enabled.

#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "buttons.h"

/*
 * Main function that sets clocks, game
 * utils, and enables periodic interrupts
 * Input: None
 * Output: None
 */
int main(void) {

  // Sets the master oscillator, CPU, and clocks.
  configureClocks();

  // Sets led, buzzer, and buttons.
  led_init();
  buzzer_init();
  buttons_init();

  // Enables periodic intterupts.
  enableWDTInterrupts();

  // CPU off, GIE on
  or_sr(0x18);
}
