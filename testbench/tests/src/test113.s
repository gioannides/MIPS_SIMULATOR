.set noat
.set noreorder

start:
addi $2,$2,0xFFFF
sll $2,$2,16
addi $2,$2,0xFFFF
sra $2,$2,31
jr $0
nop
