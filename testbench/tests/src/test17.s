.set noat
.set noreorder

start:
addi $3, $3, 3
sll $3, $3, 28
addi $3, $3, 4
addi $4, $4, 0x41
sw $4, 0($3)
jr $0
