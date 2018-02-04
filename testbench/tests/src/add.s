.set noreorder
.set noat

li $3, 0x5
li $4, 0x3
add $2,$3,$4
jr $0
nop			# return 8
