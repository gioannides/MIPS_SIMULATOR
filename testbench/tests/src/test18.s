.set noat
.set noreorder

start:
addi $3, $3, 3
sll $3, $3, 28
lw $2, 0($3)
sw $2, 4($3)
jr $0

