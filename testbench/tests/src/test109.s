.set noat
.set noreorder

start:
addi $4,$4,0xFFFF
sll $4,$4,16
addi $4,$4,0xFFFF
addi $2,$2,1
sub $2,$2,$2
jr $0
nop
