	.data
	.global red_on
red_on:	.byte 0

	.global green_on
green_on: .byte 0

	.global led_changed
led_changed: .byte 0
	     .align 2

red_val: .byte 0
	 .byte 1		;1 right for b0?

green_val: .byte 0
	   .byte 0x40		;1 right for b6?
	   
	
	.text
	.global led_init
led_init: 
	BIS.b #65, &P1DIR 	;sets bits 6 and 0 for output for P1.
	mov.b #1, &led_changed
	call #led_update
	ret

led_update:
	cmp.b #0, &led_changed 	; led_changed - 0
	jz fi			;jmp if led_changed == 0
	sub #1, r1		;decrement sp for ledFlags
	mov &red_val, r12	;
	add &red_on, r12	;r12 now has &red_val[red_on]

	mov &green_val, r13
	add &green_on, r13	;r13 now has &green_val[green_on]

	bis.b O(r13), 0(r12)	;redVal[red_on] | greenVal[green_on]

	mov 0(r12), 0(r1)	;assign val to ledFlags

	mov.b #oxff, r12	;assign 0xff to r12
	xor.b #65, r12		;oxff^LEDS
	bis.b o(r1), r12	;OR with ledFlags
	and.b r12, &P1OUT	;clear bits for off leds

	bis.b 0(r1), &P1Out	; set bit for on leds

	mov #0, &led_changed
	
fi:
	add #1, r1		;increment stack pointer, to remove local var.
	ret			
