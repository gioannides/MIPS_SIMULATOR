.set noreorder

start:
	li $t1, 0x7FFFFFFF
	sltiu $v0, $t1, 0xFFFF
	jr $zero
