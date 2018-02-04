.set noreorder

li $3,0xFFFFFFFF
li $4,0xFFFFFFFF
mthi $4
div $3,$4
mfhi $2
jr $0
nop			#return 0
