.set noreorder
.set noat

li $3, 0x20000000
addi $2,$2,0xFFFF
jr $3
nop			#return 245
