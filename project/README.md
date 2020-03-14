# Lab 2: Blinky-Buzzy-Toy

## Location
The main file for the program is found in blinky_buzzy_toy.c in the current
directory. The project is further subdivided into three directories:
1. games - source and header files for the four games that represent the four
states.
2. game_utils - source and header files for the buzzer, buttons, and led.
3. states_and_interrupts - source and header files for the state transitions
and interrupt handlers.

## Instructions
To run the game, please follow the instructions lisited below:
1. Go to demos/timerLib and type 'make install'
2. Then in the project directory type 'make load' and the program will be
downloaded to the msp430.
3. The first state, representing the first game, is a musical arragement. To
continue to the next state, press BTN1.
4. The second state, representing the second game, is find the button that
changes the pitch. Essentially, either BTN1, BTN2, or BTN3 are mapped to
random pitch. When you select the correct button, the pitch will change. Look
at the lights to also tell when the correct button is pressed (green light
will turn on) or the incorrect button is pressed (red light will turn on). To
move to the next state, press BTN4.
5. The third state, representing the third game, is called catch red. The
objective is to press BTN4 every time the red light blinks. If you continue to
hit the button at this time, the lights will incrementally get faster. If you
incorrectly hit BTN4 when the red light is not shining, the game will
restart. To move to the next state press BTN3.
6. The fourth state, representing the fourth game is simon. The game in total
has 32 random moves that build up successively. First, the game will blink a
light and wait for you to press a button. If the light was green then press
BTN1. If the light was red, then press BTN4. If you successfully entered the
correct pattern, the pattern will be re-modeled by shining the led pattern and
a new pattern will be added. After the pattern is done being displayed, press
the new pattern (BTN1 for green, BTN2 for red). If you incorrectly enter the
wrong pattern, the game will start from the beginning again. To go back to
state 1, press BTN3.

## Project Description
