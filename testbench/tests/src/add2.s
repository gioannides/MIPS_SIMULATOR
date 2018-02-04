.set noreorder
.set noat

li $3, 0xFFFFFFF
li $4, 0xFFFFFFF
add $2,$3,$4
jr $0
nop			#TEST NEGATIVE, return 254
