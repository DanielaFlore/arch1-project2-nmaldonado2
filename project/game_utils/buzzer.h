// Nichole Maldonado and Previous Commits
// This is the header file for buzzer.h
// which has functions to initialize the
// buzzer and set the frequency of the buzzer.

#ifndef buzzer_included
#define buzzer_included

#define NOTE_E 2637
#define NOTE_E_FLAT 2489
#define NOTE_B 1975
#define NOTE_D 2349
#define NOTE_C 2093
#define NOTE_A 1760

// Initialize the buzzer.
void buzzer_init();

// Set the period based on the number of
// cycles and mute (number of bits shifted).
void buzzer_set_period(short cycles, char mute);

// Sets the sound based on the note_num
void set_sound(unsigned char note_num);

#endif // included
