.set noreorder
.set noat

li $4,0xFFFFFFFF
li $3,31
addi $2,$0,34
sllv $2,$4,$3
jr $0
nop			#return 0
