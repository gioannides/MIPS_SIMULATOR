.set noreorder

start:
	bgtz $t1, start + 12
	nop
	li $v0, 1
	jr $zero
	nop
