// Nichole Maldonado and Previous Commits
// This file contains functions that initializes
// the leds and sets the leds on or off
// based on the color (green or red).

#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

/*
 * Initializes the LEDS by opening the corresponding
 * DIR transmission gates and updating the leds
 * accordingly (Turning them off) at the beginning.
 * Input: None
 * Output: None
 */
void led_init()
{
  // Bits attached to the leds are outputs
  P1DIR |= LEDS;
  led_change();
}

/*
 * Function that turns the green and red
 * leds on/off based on the flags red_on
 * and green_on
 * Input: None.
 * Output: None.
 */
void led_change()
{
    // Turns on bits
    // if red on then 0booooooo1
    // if green on then 0b01000000
    char ledFlags = redVal[red_on] | greenVal[green_on];

    // Clear bits for off leds.
    P1OUT &= (0xff^LEDS) | ledFlags;

    // Set bits for on leds.
    P1OUT |= ledFlags;
}

/*
 * Function that turns on the green
 * led only.
 * Input: None.
 * Output: None.
 */
void turn_on_green()
{
  green_on = 1;
  red_on = 0;
  led_change();
}

/*
 * Function that turns on the red
 * led only.
 * Input: None.
 * Output: None.
 */
void turn_on_red()
{
  red_on = 1;
  green_on = 0;
  led_change();
}

/*
 * Function that turns off the green
 * led only.
 * Input: None.
 * Output: None.
 */
void turn_off_green()
{
  green_on = 0;
  led_change();
}

/*
 * Function that turns off the red
 * led only.
 * Input: None.
 * Output: None.
 */
void turn_off_red()
{
  red_on = 0;
  led_change();
}

/*
 * Function that turns off the red and green
 * led.
 * Input: None.
 * Output: None.
 */
void turn_off_green_red()
{
  red_on = green_on = 0;
  led_change();
}
