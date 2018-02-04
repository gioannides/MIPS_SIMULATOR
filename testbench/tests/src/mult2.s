.set noreorder
.set noat

li $3,0xFFFFFFFF
li $4,0x7FFFFFFF
mult $3,$4
mflo $2
srl $2,$2,31
jr $0
nop			#return 1
