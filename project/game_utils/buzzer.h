// Nichole Maldonado and Previous Commits
// This is the header file for buzzer.h
// which has functions to initialize the
// buzzer and set the frequency of the buzzer.

#ifndef buzzer_included
#define buzzer_included

// Initialize the buzzer.
void buzzer_init();

// Set the period based on the number of
// cycles and mute (number of bits shifted).
void buzzer_set_period(short cycles, char mute);

// Sets the sound based on the note_num
void set_sound(unsigned char note_num);

#endif // included
