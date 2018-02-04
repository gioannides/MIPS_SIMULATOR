.set noat
.set noreorder

start:
addi $2,$2,0xFFFF
sll $2,$2,16
addi $2,$2,0xFFFF
or $2,$2,$0
jr $0
nop
