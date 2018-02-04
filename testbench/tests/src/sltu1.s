.set noreorder
.set noat

li $3, 0xFFFFFFFF
li $4, 0xFFFFFFF0
addi $2,$0,56
sltu $2,$3,$4
jr $0
nop			#return 0
