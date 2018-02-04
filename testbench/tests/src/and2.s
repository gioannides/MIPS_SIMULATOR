.set noreorder
.set noat

li $3, 0xFFFFFFF
li $4, 0x1
and $2,$3,$4
jr $0
nop			#$2 = 1
