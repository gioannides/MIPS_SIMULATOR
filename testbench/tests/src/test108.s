.set noat
.set noreorder

start:
addi $4,$4,0x1
sll $2,$4,7
srl $2,$2,7
jr $0
nop
