.set noreorder
.set noat

li $3,0x0
li $4,0xFFFFFFF
subu $2,$3,$4
jr $0
nop			#return 1
