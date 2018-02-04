.set noreorder
.set noat

li $3,0xFFFFFFFF
li $4,31
sllv $2,$3,$4
srav $2,$3,$4
jr $0
nop			#return 255
