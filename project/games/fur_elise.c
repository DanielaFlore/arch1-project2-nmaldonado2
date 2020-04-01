// Nichole Maldonado
// This file contains functions that play the
// first nine notes of fur elise and
// turn on bright or dim lights accordingly.

#include "fur_elise.h"
#include "buzzer.h"
#include "led.h"

static void set_light(char conductor_position, char change_dimness);

/*
 * Function that sets the light based on
 * the conductors position in the array of 
 * notes and whether the light will be dimmed.
 * Input: None.
 * Output: None.
 */
static void set_light(char conductor_position, char change_dimness)
{
  static char dim_light = 0;

  // If change_dimness is true, then flip the bit
  // for dim_light.
  dim_light = (change_dimness) ? dim_light^1 : dim_light;

  // If the conductor is pointing to an even
  // position, turn_green on.
  if (conductor_position % 2 == 0) {
    turn_on_green();
  }

  // If the conductor is pointing to an odd position,
  // turn on red.
  else {
    turn_on_red();
  }

  // If dim the light, turn it off.
  // turning on and off the light quickly,
  // dims the light.
  if (dim_light) {
    turn_off_green_red(); 
  }
}

/*
 * Function that plays fur elise and initiates
 * the turning on of lights accordingly.
 * Input: None
 * Output: None
 */
void fur_elise_sound()
{
  char sound_notes[] = {1,2,1,2,1,3,4,5,6};
  static char conductor = 0;
  static char blink_count = 0;

  // If the blink_count is less than 200,
  // then turn the lights on and off accordingly.
  if (++blink_count < 200) {
    set_light(conductor, ((blink_count == 1)? 1 : 0));
  }

  // Otherwise set the sound to the current
  // note.
  else {
    set_sound(sound_notes[conductor]);
  }

  // If the blink_count is greater than
  // 225, move on to the next note.
  // Increment again for faster tune.
  if (++blink_count > 225) {

    // There are nine notes in the array.
    if (++conductor > 8) {
      conductor = 0;
    }
    blink_count = 0;
  }
}  
