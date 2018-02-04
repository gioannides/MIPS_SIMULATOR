.set noreorder
.set noat

li $4,0xFFFFFFFF
sra $2,$4,31
jr $0
nop			#return 255
