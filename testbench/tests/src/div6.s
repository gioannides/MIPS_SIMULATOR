.set noreorder


li $3,0x1
li $4,0x2
div $3,$4
mfhi $2
jr $0
nop			#return 1
