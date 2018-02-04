.set noreorder
.set noat

li $4,0x1
li $3,31
sllv $2,$4,$3
srlv $2,$2,$3
jr $0
nop			#return 1
