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
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o stateMachines.o led.o buzzer.o buttons.o p2_interrupt_handler.o wdInterruptHandler.o simon.o catch_red.o find_frequency.o fur_elise.o ../demos/lib/libTimer.a game_three_to_four_transition.s
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf

blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h led.h buzzer_buttons/buzzer.h buzzer_buttons/buttons.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I../demos/timerLib -Ibuzzer_buttons blinky_buzzy_toy.c


led.o: led.c led.h

wdInterruptHandler.o: wdInterruptHandler.c led.h games/simon.h games/catch_red.h games/find_frequency.h games/fur_elise.h stateMachines.h

stateMachines.o: led.h stateMachines.h stateMachines.c led.h buzzer_buttons/buttons.h games/simon.h games/find_frequency.h games/catch_red.h game_three_to_four_transition.s
	msp430-elf-gcc -mmcu=msp430g2553 -c -Ibuzzer_buttons -Igames stateMachines.c

buzzer.o: buzzer_buttons/buzzer.c buzzer_buttons/buzzer.h ../demos/timerLib/libTimer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I../demos/timerLib buzzer_buttons/buzzer.c

p2_interrupt_handler.o: p2_interrupt_handler.c buzzer_buttons/buttons.h stateMachines.h led.h games/catch_red.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -Igames -Ibuzzer_buttons p2_interrupt_handler.c

buttons.o: buzzer_buttons/buttons.h led.h buzzer_buttons/buttons.c
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ buzzer_buttons/buttons.c

simon.o: games/simon.h games/simon.c led.h buzzer_buttons/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons games/simon.c

catch_red.o: games/catch_red.h games/catch_red.c led.h buzzer_buttons/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons games/catch_red.c

find_frequency.o: games/find_frequency.h games/find_frequency.c buzzer_buttons/buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons games/find_frequency.c

fur_elise.o: games/fur_elise.h games/fur_elise.c buzzer_buttons/buzzer.h led.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ -Ibuzzer_buttons games/fur_elise.c
