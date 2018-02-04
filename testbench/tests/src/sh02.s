.set noreorder

start:
	li $t1, 0x00000003
	li $t2, 0x20000000
	li $t3, 0x1
	sw $t3, 0($t2)
	sh $t1, 0($t2)
	lw $v0, 0($t2)
	jr $zero
	nop

