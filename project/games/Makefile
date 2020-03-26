# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: simon catch_red find_frequency fur_elise

clean:
	rm -f *.o

simon: simon.h simon.c ../game_utils/led.h ../game_utils/buzzer.h
	${CC} ${CFLAGS} -c -I./ -I../game_utils  simon.c

catch_red: catch_red.h catch_red.c ../game_utils/led.h ../game_utils/buzzer.h
	${CC} ${CFLAGS} -c -I./ -I../game_utils catch_red.c

find_frequency: find_frequency.h find_frequency.c ../game_utils/buzzer.h ../game_utils/buttons.h
	${CC} ${CFLAGS} -c -I./ -I../game_utils find_frequency.c

fur_elise: fur_elise.h fur_elise.c ../game_utils/buzzer.h ../game_utils/led.h
	${CC} ${CFLAGS} -c -I./ -I../game_utils fur_elise.c
