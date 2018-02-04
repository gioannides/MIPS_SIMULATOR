.set noreorder

start:
	li $t1, 0x20000000
	li $t2, 0x01
	sw $t2, 0($t1)
	lwl $v0, 3($t1)
	srl $v0, $v0, 24
	jr $zero
	nop
