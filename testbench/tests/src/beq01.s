.set noat
.set noreorder

start:
	beq $zero, $zero, start + 8
	nop
	li $v0, 1
	jr $zero
	nop
