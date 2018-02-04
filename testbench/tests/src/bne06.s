.set noat
.set noreorder

start:
	bne $t1, $t2, start + 12
	nop
	li $v0, 1
	jr $zero
	nop
