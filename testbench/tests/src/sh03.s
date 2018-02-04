.set noreorder

start:
	li $t1, 0x1
	li $t2, 0x20000000
	sh $t1, 1($t2)
	lw $v0, 0($t2)
	jr $zero
	nop

