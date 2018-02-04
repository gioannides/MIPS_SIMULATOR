.set noreorder

start:
	bltzal $0, start + 8
	add $v0, $zero, $ra
	jr $zero
	nop
