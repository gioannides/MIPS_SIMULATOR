.set noreorder
.set noat

li $3, 0x7FFFFFFF
li $4, 0x1
add $2,$3,$4
jr $0
nop			#TEST OVERFLOW return 246
