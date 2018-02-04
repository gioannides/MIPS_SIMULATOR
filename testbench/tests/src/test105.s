.set noat
.set noreorder

start:
addi $4,$4,0xFFFF
addi $3,$3,0x0
slt $2,$4,$3
jr $0
nop
