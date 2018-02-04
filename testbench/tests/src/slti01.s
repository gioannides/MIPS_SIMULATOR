.set noreorder

start:
	li $t1, 0x00000001
	slti $v0, $t1, 0x0002
	jr $zero
