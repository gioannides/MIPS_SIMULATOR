.set noreorder
.set noat

li $3, 0xFFFFFFF0
li $4, 0xFFFFFFFF
addi $2,$0,23
slt $2,$3,$4
jr $0
nop			#return 1
