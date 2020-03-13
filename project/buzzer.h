#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles, short mute);
void buzzer_turn_off();
void buzzer_turn_on();

void set_sound(char music_note);
void set_frequency(short cycles, short mute);

#endif // included
