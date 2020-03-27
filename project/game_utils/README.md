# Description

This subdirectory contains the source code for the main components of the
msp430 which include the the buttons, buzzer, and led. Within each source file
are methods that are used to adjust the buzzer period, turn on a specific
light, or initialize a button, for example.

Additionally, the Makefile located in this directory has the capability to
make the object files for each source file. Simply type 'make' to build the
library and 'make clean' to remove all .o files.
