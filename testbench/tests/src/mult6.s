.set noreorder
.set noat

li $3,0x7FFFFFFF
li $4,0x7FFFFFFF
mult $3,$4
mfhi $2
jr $0
nop			#return 255
