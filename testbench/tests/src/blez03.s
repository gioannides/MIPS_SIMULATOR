.set noreorder

start:
	li $t1, 1
	blez $t1, start + 16
	nop
	li $v0, 1
	jr $zero
	nop
