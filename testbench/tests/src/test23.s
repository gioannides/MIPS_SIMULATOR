.set noat
.set noreorder

hello_there:
addi $3, $3, 0x7FFF
.word 0x08000000
nop
nop
