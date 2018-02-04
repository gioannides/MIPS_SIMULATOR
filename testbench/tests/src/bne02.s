.set noat
.set noreorder

start:
	li $t1, 1
	bne $t1, $zero, start + 8
	nop
	li $v0, 1
	jr $zero
	nop
