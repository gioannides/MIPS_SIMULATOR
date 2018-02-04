.set noreorder

start:
	bltz $0, start + 12
	nop
	li $v0, 1
	jr $zero
	nop
