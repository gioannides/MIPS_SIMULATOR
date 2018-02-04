.set noreorder

start:
	li $t1, 0x10000000
	blez $0, start + 16
	nop
	jr $zero
	li $v0, 1
	jr $zero
	nop
