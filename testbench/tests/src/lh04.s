.set noreorder

start:
	li $t1, 0x23FFFFFC
	li $t2, 0x00000100
	sw $t2, ($t1)
	lh $v0, 4($t1)
	jr $zero
	nop

