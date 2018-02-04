.set noreorder

start:
	li $t1, 1
	bgtz $t1, start + 16
	nop
	jr $zero
	li $v0, 1
	jr $zero
	nop
