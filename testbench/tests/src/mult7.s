.set noreorder
.set noat

li $3,0x7FFFFFFF
li $4,0x7FFFFFFF
mult $3,$4
mflo $2
jr $0
nop			#return 0
