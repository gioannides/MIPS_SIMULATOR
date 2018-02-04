.set noreorder

start:
	blez $0, start + 12
	nop
	jr $zero
	li $v0, 1
	jr $zero
	nop
