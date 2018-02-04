.set noreorder

start:
	li $t1, 0x20000000
	li $v0, 0x80000000
	lwr $v0, 1($t1)
	srl $v0, $v0, 31
	jr $zero

