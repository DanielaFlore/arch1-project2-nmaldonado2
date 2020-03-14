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
	jc end
	mov.b #150, &light_speed ; set light_speed to 150
end:	
	ret
