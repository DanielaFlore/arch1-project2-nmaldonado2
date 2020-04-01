# Description

This subdirectory contains source files for the state implementations and
interrupt handlers. The general purpose of the source files are highlighted
below.
* p2_interrupt_handler - handles interrupts from Port 2 and calls the
corresponding interrupt handler for that game/state in state_machine_interrupt_handlers.c
* state_machine_interrupt_handlers.c - performs the interrupt handler for that states based on
the game_num.
* wdt_interrupt_handler.c - handles the watchdog timer interrupts and
specifies which game to play based on the game_num.
* games_two_three_interrupt_handlers.s - assembly code for the interrupt handling and
state transitions for games two and three.

Additionally, the Makefile located in this directory has the capability to
make the object files for each source file. Simply type 'make' to build the
library and 'make clean' to remove all .o files.
