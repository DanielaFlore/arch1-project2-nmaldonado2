	.text
	.global game_three_interrupt_handler
game_three_interrupt_handler:
	
	mov.b #0xf, r12
	and.b &P2IN, r12 
	cmp.b #0xd, r12
	jnz else_if
	mov.b #4, &game_num
	jmp end
else_if:
	cmp.b #0x7, r12
	jnz end
	cmp.b #0, &red_on	;red_on - 0
	jz second_nested_if	;jmp if red_on == 0
	sub.b #0x5, &light_speed
second_nested_if:
	cmp.b #0, &red_on
	jnz end
	mov #15, r12
	cmp.b &light_speed, r12
	jc end
	mov.b #150, &light_speed
end:	
	ret
