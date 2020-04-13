;;; Nichole Maldonado
;;; Assembly file that handles the state
;;; transitions for game two (find_frequency)
;;; and game three (catch_red).

;;; State Three Machine
;;; Interrupt handler and state machine for
;;; game 3, catch red that will increment the
;;; light_speed if the fourth button is pressed
;;; when the red led is on. Otherwise the
;;; game will be reset to a slower speed.
;;; Input: None
;;; Output: None
	.arch msp430g2553
	.p2align 1,0
	
	.text
	.global game_three_interrupt_handler
game_three_interrupt_handler:	
	mov.b #0xf, r13
	and.b &P2IN, r13 
	cmp.b #0xd, r13		; If BTN2 is pressed, game num is set to 4.
	jnz else_if
	mov.b #150, &light_speed ; reset ligh_speed
	mov.b #4, &game_num
	jmp end
else_if:
	cmp.b #0x7, r13		; If BTN4 is pressed
	jnz end
	cmp.b #0, &red_on	; and red_on,
	jz second_nested_if	
	sub.b #0x5, &light_speed ; the subtract 5 from light_speed.
second_nested_if:
	cmp.b #0, &red_on	; If red_on == 0
	jnz end
	mov #15, r13
	cmp.b &light_speed, r13	; or the light speed is <= 15
	jhs end			;goto end
	mov.b #150, &light_speed ; set light_speed to 150
end:	
	ret

;;; State machine for game three.
;;; Interrupt handler for find_frequency that
;;; will go to the next state if the fourth
;;; fourth button is pressed. Otherwise a green led light
;;; will shine if the frequency_btn and actual button
;;; pressed match
;;; Input: None
;;; Output: None
jt:
	.word case_seven			;7
	.word default			;8
	.word default			;9
	.word default			;10
	.word default			;11
	.word default			;12
	.word default			;13
	.word default			;14
	.word case_fifteen			;15

	.global game_two_interrupt_handler
game_two_interrupt_handler:
	mov #0xf, r12
	and.b &P2IN, r12 	;P2IN & BUTTONS in r12
	sub.b #7, r12		;(P2IN & BUTTONS) - 7
	jlo default		;borrows if P2IN & BUTTONS is less than 7, so carry == 0.
	add r12, r12
	mov jt(r12), r0		; Go to case_seven, case_fifteen, or default
case_seven:
	mov.b #3, &game_num	; If BTN4 is pressed, go to next state.
	jmp end_game_two
case_fifteen:
	call #turn_off_green_red ;If no buttons are pressed, turn off leds.
	jmp end_game_two
default:	
	mov.b #0xf, r12
	and.b &P2IN, r12
	cmp.b &frequency_btn, r12 ;If the button pressed matches the freqency_btn
	jnz else
	call #turn_on_green	;then turn on green
	mov.b #-1, &frequency_btn ;and set frequency button to a -1.
	jmp end_game_two
else:
	call #turn_on_red	;Otherwise an incorrect button was pressed so turn on red.
end_game_two:	
	ret
