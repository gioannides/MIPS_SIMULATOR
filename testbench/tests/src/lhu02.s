.set noreorder

start:
	li $t1, 0x20000004
	li $t2, 0x00000001
	sw $t2, -4($t1)
	lhu $v0, -2($t1)
	jr $zero
	nop

