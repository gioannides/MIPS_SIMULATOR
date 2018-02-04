.set noat
.set noreorder

start:
addi $3, $3, 2
sll $3, $3, 28
addi $4, $4, 4
sll $4, $4, 24
add $3, $4, $3
addi $3, $3, -1
lwr $3, -1($3)
