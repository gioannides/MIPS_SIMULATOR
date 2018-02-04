.set noreorder

start:
	li $v0, 0x00000001
	sltiu $v0, $zero, 0x0000
	jr $zero
