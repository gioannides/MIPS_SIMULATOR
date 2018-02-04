.set noreorder

start:
	li $t1, 0x80000000
	bltz $t1, start + 20
	nop
	jr $zero
	nop
	li $v0, 1
	jr $zero
	nop
