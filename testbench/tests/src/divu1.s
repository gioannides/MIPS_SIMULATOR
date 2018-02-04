.set noreorder
.set noat

li $3,0xFFFFFFFF
li $4,0x1
divu $3,$4
mflo $2
jr $0
nop			#return 255
