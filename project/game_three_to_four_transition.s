	.text
	.global game_three_interrupt_handler
game_three_interrupt_handler:
	
	mov.b #0xf, r13
	and.b &P2IN, r13 
	cmp.b #0xd, r13
	jnz else_if
	mov.b #4, &game_num
	jmp end
else_if:
	cmp.b #0x7, r13
	jnz end
	cmp.b #0, &red_on	;red_on - 0
	jz second_nested_if	;jmp if red_on == 0
	sub #0x5, r12
second_nested_if:
	cmp.b #0, &red_on
	jnz end
	mov #15, r13
	cmp.b r12, r13
	jc end
	mov.b #150, r12
end:	
	ret
