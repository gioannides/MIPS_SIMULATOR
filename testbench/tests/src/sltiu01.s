.set noreorder

start:
	li $t1, 0x00000001
	sltiu $v0, $t1, 0x0002
	jr $zero
