.set noreorder
.set noat

li $4,0x7FFFFFFF
sra $2,$4,30
jr $0
nop			#return 1
