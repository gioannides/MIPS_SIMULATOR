.set noreorder
.set noat

li $3, 0x7FFFFFF
li $4, 0x7FFFFFF
addu $2,$3,$4
jr $0
nop			#TEST NO OVERFLOW, return 254
