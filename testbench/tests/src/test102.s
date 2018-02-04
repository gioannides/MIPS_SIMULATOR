.set noat
.set noreorder

start:
addi $2,$2,0xFFFF
sll $2,$2,16
addi $2,$2,0xFFFF
addi $3,$3,0xFFFF
and $2,$2,$3
jr $0
nop
