# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blinky_buzzy_toy.elf 

#additional rules for files
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o stateMachines.o led.o catch_red.o buzzer.o buttons.o p2_interrupt_handler.o wdInterruptHandler.o simon.o find_frequency.o fur_elise.o ../demos/lib/libTimer.a states_and_interrupts/game_three_to_four_transition.s
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf

blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h game_utils/led.h game_utils/buzzer.h game_utils/buttons.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I../demos/timerLib -Igame_utils blinky_buzzy_toy.c


led.o: game_utils/led.c game_utils/led.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -Igame_utils game_utils/led.c

wdInterruptHandler.o: states_and_interrupts/wdInterruptHandler.c game_utils/led.h games/simon.h games/catch_red.h games/find_frequency.h games/fur_elise.h states_and_interrupts/stateMachines.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -Istates_and_interrupts -Igames -Igame_utils states_and_interrupts/wdInterruptHandler.c

stateMachines.o: game_utils/led.h states_and_interrupts/stateMachines.h states_and_interrupts/stateMachines.c game_utils/buttons.h games/simon.h games/find_frequency.h games/catch_red.h states_and_interrupts/game_three_to_four_transition.s
	msp430-elf-gcc -mmcu=msp430g2553 -c -Igames -Istates_and_interrupts -Igame_utils states_and_interrupts/stateMachines.c

buzzer.o: game_utils/buzzer.c game_utils/buzzer.h ../demos/timerLib/libTimer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I../demos/timerLib game_utils/buzzer.c

p2_interrupt_handler.o: states_and_interrupts/p2_interrupt_handler.c game_utils/buttons.h states_and_interrupts/stateMachines.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -Igames -Istates_and_interrupts -Igame_utils states_and_interrupts/p2_interrupt_handler.c

buttons.o: game_utils/buttons.h game_utils/buttons.c
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Igame_utils game_utils/buttons.c

simon.o: games/simon.h games/simon.c game_utils/led.h game_utils/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Igame_utils -Iled games/simon.c

catch_red.o: games/catch_red.h games/catch_red.c game_utils/led.h game_utils/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Igame_utils -Igames games/catch_red.c

find_frequency.o: games/find_frequency.h games/find_frequency.c game_utils/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Igame_utils games/find_frequency.c

fur_elise.o: games/fur_elise.h games/fur_elise.c game_utils/buzzer.h game_utils/led.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Igame_utils games/fur_elise.c
