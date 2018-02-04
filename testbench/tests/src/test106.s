.set noat
.set noreorder

start:
addi $4,$4,0xFFFF
sll $4,$4,16
addi $4,$4,0xFFFF
addi $3,$3,0xFF
sltu $2,$4,$3
jr $0
nop
