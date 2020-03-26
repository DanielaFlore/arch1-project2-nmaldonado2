# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all:
	(cd ../demos/timerLib && make install)
	(cd game_utils && make)
	(cd games && make)
	(cd states_and_interrupts && make)

#additional rules for files
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o states_and_interrupts/stateMachines.o game_utils/led.o games/catch_red.o game_utils/buzzer.o game_utils/buttons.o states_and_interrupts/p2_interrupt_handler.o states_and_interrupts/wdInterruptHandler.o games/simon.o games/find_frequency.o games/fur_elise.o ../demos/lib/libTimer.a states_and_interrupts/game_three_to_four_transition.s
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	(cd ../demos/timerLib && make clean)
	(cd games && make clean)
	(cd game_utils && make clean)
	(cd states_and_interrupts && make clean)
	rm -f *.o *.elf
	rm -rf ../demos/lib ../demos/h

blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h game_utils/led.h game_utils/buzzer.h game_utils/buttons.h
	${CC} ${CFLAGS} -c -I../demos/timerLib -Igame_utils blinky_buzzy_toy.c
