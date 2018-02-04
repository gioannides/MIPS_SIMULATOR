.set noat
.set noreorder

addi $2, $2, 0xFFFF
addi $3, $0, 0x0002
sll $3, $3, 28
sw $2, 8($3)
lw $2, 8($3)
sb $2, 8($3)
lb $2, 8($3)
jr $0


