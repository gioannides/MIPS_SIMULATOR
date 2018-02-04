.set noreorder
.set noat

li $3,0x8
li $4,0x9
sub $2,$4,$3
jr $0
nop			#return 1
