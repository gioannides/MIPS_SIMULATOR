.set noat
.set noreorder

start:
addi $2,$0,0x7FFF
sll $2,$2,16
addi $2,$2,0xFFFF
addi $3,$3,0xFFFF
sll $3,$3,16
addi $3,$3,0xFFFF
sub $2,$2,$3
jr $0
nop
