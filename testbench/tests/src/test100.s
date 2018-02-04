.set noat
.set noreorder

start:
addi $2,$0,0x7FFF
sll $2,$2,16
addi $2,$2,0xFFFF
add $2,$2,$2
jr $0
nop
