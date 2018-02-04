.set noat
.set noreorder

start:
	lui $t1, 0x1000
	addi $t1, $t1, 24
	jalr $t1
	nop
	jr $0
	nop

j1:	addi $v0, $v0, 5
	jr $31
	nop
