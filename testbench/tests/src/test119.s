.set noat
.set noreorder

start:
addi $3,$0,0xFFFF
sll $3,$3,16
addi $3,$3,0xFFFF
addi $5,$5,31
srlv $2,$3,$5
jr $0
