.set noreorder
.set noat

li $3, 0x0
li $4, 0x0
addi $2,$0,67
sltu $2,$3,$4
jr $0
nop			#return 0
