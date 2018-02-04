.set noreorder
.set noat

li $3, 0xFFFFFFFF
li $4, 0xFFFFFFFF
addi $2,$0,45
slt $2,$3,$4
jr $0
nop			#return 0
