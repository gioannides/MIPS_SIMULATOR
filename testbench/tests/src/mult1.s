.set noreorder
.set noat

li $3,0x3
li $4,0x7FFFFFF
mult $3,$4
mflo $2
jr $0
nop			#return 253
