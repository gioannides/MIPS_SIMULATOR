.set noreorder
.set noat

li $3,0x0
li $4,0x7FFFFFFF
sub $2,$3,$4
sub $2,$2,$4
jr $0
nop			#return 246
