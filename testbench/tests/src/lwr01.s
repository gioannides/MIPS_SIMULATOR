.set noreorder

start:
	li $t1, 0x20000000
	li $t2, 0x10000000
	sw $t2, 0($t1)
	lwr $v0, 0($t1)
	srl $v0, $v0, 4
	jr $zero
	nop
