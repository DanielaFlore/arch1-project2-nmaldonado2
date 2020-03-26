// Nichole Maldonado
// This file is for game 3 and alternates lights
// based on the light_speed.

#include "catch_red.h"
#include "led.h"
#include "buzzer.h"

unsigned char light_speed = 150;

static void alternate_lights();

/*
 * Function that alternates the lights 
 * between red and green.
 * Input: None
 * Output: None
 */
static void alternate_lights()
{
  // Turn on red.
  if (!red_on){
    buzzer_set_period(1000, 1);
    turn_on_red();
  }

  // Turn on green.
  else {
    buzzer_set_period(9000, 1);
    turn_on_green();
  }
}

/*
 * Function that issues the alternating of the
 * leds when the blink_count reaches the
 * light_speed.
 * Input: None.
 * Output: None.
 */
void catch_red()
{
  static char blink_count = 0;

  // When the blink_count equals the light_speed
  // then alternate the lights.
  if (++blink_count == light_speed) {
    alternate_lights();
    blink_count = 0;
  }
}
