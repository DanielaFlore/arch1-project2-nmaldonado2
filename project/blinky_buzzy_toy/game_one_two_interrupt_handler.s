
	.text
	.global game_three_interrupt_handler
game_three_interrupt_handler:
	
	mov.b #0xf, r12
	and.b &P2IN, r12 
	mov.b #0xd, r13		;~BTN2
	and.b #0xf, r13
	cmp.b r12, r13
	jnz else_if
	mov.b #4, &game_num
	jmp end
else_if:
	mov.b #0x7, r13		;~BTN4
	and.b #0xf, r13
	cmp.b r12, r13
	jnz end
	cmp.b #0, &red_on
	jz first_nested_if
	sub #0x5, &light_speed
first_nested_if:
	cmp.b #0, &red_on
	jnz second_nested_if
	mov.b #150, &light_speed
	jmp end
second_nested_if:
	mov #15, r12
	cmp.b &light_speed, r12
	jc end
	mov.b #150, &light_speed
end:	
	ret
