.set noreorder

start:
	li $t1, 0x20000000
	li $t2, 0x00008000
	sw $t2, 0($t1)
	lh $v0, 2($t1)
	srl $v0, $v0, 15
	jr $zero
	nop

