.set noat
.set noreorder

addi $3, $3, 2
sll $3, $3, 28
addi $4, $4, 9
sll $4, $4, 16
sw $4, 4($3)
lwr $2, 5($3)
jr $0
