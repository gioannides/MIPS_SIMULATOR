.set noreorder
.set noat

li $3, 0xFFFFFFFF
sll $2,$3,31
sra $2,$2,31
jr $0
nop			#return 255
