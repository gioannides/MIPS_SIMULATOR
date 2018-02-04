.set noat
.set noreorder

lui $1,4660
ori $1,22136
lui $3,39612
ori $3,$3,57072
lui $4,8192
sw $1,0($4)
sw $3,4($4)
lb $5,0($4)
lb $6,1($4)
lb $7,4($4)
lbu $8,5($4)
addu $5,$5,$6
addu $7,$7,$8
addu $9,$7,$5
sb $9,1($4)
lw $9,0($4)
lui $1,4764
ori $1,$1,22129
sub $9,$9,$1
addi $2,$9,0
jr $0
nop			
