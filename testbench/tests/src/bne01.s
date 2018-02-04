.set noat
.set noreorder

start:
	ori $t1, $t1, 1
	bne $t1, $zero, start + 12
	nop
	li $v0, 1
	jr $zero
	nop
