.set noreorder
.set noat

li $3, 0x0
li $4, 0x1
sltu $2,$3,$4
jr $0
nop			#return 1
