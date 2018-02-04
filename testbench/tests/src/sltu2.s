.set noreorder
.set noat

li $3, 0xFFFFFFFF
li $4, 0xFFFFFFFF
addi $2,$0,3
sltu $2,$3,$4
jr $0
nop			#return 0
