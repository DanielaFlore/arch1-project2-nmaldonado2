// Nichole Maldonado
// Header file for simon.c that contians the
// functions for simon which shows a pattern
// of lights and adds a pattern to game_pattern
// if add_pattern is set to true. Note that
// only 32 game patterns can be reached.

extern unsigned char add_pattern;
extern unsigned char curr_pattern;
extern unsigned char wait_for_pattern;
extern unsigned char game_pattern[32];

// Function that initiates the printing of
// game patterns and adding to the pattern.
void simon();


