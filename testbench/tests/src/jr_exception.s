.set noreorder
.set noat

li $3, 0xFFFFFFFF
jr $3
nop			#return EXCEPTION 245
