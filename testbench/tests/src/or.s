.set noreorder
.set noat

li $3, 0xFFFFFFFF
li $4, 0xFFFFFFFF
or $2,$3,$4
jr $0
nop			#return 255
