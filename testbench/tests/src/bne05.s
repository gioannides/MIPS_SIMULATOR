.set noat
.set noreorder

start:
	li $v0, 1
	li $t1, 1
	bne $t1, $zero, start + 24
	nop
	jr $zero
	nop
	bne $t1, $zero, start + 16
	nop
