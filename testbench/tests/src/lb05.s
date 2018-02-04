.set noreorder

start:
	li $t1, 0x20000000
	li $t2, 0x00008000
	sw $t2, ($t1)
	lb $v0, 2($t1)
	srl $v0, $v0, 7
	jr $zero
	nop

