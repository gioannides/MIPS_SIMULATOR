.set noreorder

start:
	li $v0, 1
	li $t1, 0x7FFFFFFF
	slti $v0, $t1, 0xFFFF
	jr $zero
