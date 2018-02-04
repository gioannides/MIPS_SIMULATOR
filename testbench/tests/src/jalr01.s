.set noreorder

start:
	li $t1, 0x1000001C
	jalr $2, $t1
	nop
	li $2, 1
	jr $0
	nop	
j1:
	jr $v0
	jr $zero
