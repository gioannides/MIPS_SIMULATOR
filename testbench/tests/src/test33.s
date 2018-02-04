.set noreorder
.set noat

start:
	lui $t1, 0x2000
	lui $t2, 0x8765
	ori $t2, $t2, 0x4321
	sw $t2, 0($t1)
	lwl $v0, 3($t1)
	srl $v0, $v0, 24
	jr $0

