.set noreorder
.set noat

li $3,0xFFFFFFFF
srl $2,$3,31
jr $0
nop			#return 1
