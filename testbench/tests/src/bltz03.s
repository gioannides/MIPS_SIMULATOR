.set noreorder

start:
	li $t1, 0x7FFFFFFF
	bltz $t1, start + 20
	nop
	li $v0, 1
	jr $zero
