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
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o stateMachines.o led.o buzzer.o buttons.o p2_interrupt_handler.o wdInterruptHandler.o simon.o catch_red.o find_frequency.o fur_elise.o ../demos/lib/libTimer.a states/game_three_to_four_transition.s
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf

blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h states/led.h buzzer_buttons/buzzer.h buzzer_buttons/buttons.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I../demos/timerLib -Ibuzzer_buttons -Istates blinky_buzzy_toy.c


led.o: states/led.c states/led.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -Istates states/led.c

wdInterruptHandler.o: states/wdInterruptHandler.c states/led.h games/simon.h games/catch_red.h games/find_frequency.h games/fur_elise.h states/stateMachines.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -Istates -Igames states/wdInterruptHandler.c

stateMachines.o: states/led.h states/stateMachines.h states/stateMachines.c buzzer_buttons/buttons.h games/simon.h games/find_frequency.h games/catch_red.h states/game_three_to_four_transition.s
	msp430-elf-gcc -mmcu=msp430g2553 -c -Ibuzzer_buttons -Igames -Istates states/stateMachines.c

buzzer.o: buzzer_buttons/buzzer.c buzzer_buttons/buzzer.h ../demos/timerLib/libTimer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I../demos/timerLib buzzer_buttons/buzzer.c

p2_interrupt_handler.o: states/p2_interrupt_handler.c buzzer_buttons/buttons.h states/stateMachines.h states/led.h games/catch_red.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -Igames -Ibuzzer_buttons -Istates states/p2_interrupt_handler.c

buttons.o: buzzer_buttons/buttons.h states/led.h buzzer_buttons/buttons.c
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Istates buzzer_buttons/buttons.c

simon.o: games/simon.h games/simon.c states/led.h buzzer_buttons/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons -Istates games/simon.c

catch_red.o: games/catch_red.h games/catch_red.c states/led.h buzzer_buttons/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons -Istates games/catch_red.c

find_frequency.o: games/find_frequency.h games/find_frequency.c buzzer_buttons/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons games/find_frequency.c

fur_elise.o: games/fur_elise.h games/fur_elise.c buzzer_buttons/buzzer.h states/led.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons -Istates games/fur_elise.c
