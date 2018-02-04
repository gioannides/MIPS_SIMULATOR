.set noreorder


li $3,0xFFFFFFFF
li $4,0x1
div $3,$4
mflo $2
jr $0
nop			#return 255
