.set noat
.set noreorder

lui $1,30292
ori $1,$1,12816
lui $3,8192
sw $1,0($3)
lui $4,4660
ori $4,$4,22136
lui $6,8192
addi $6,$6,4
sw $4,0($6)
lw $7,0($3)
lw $8,0($6)
addu $10,$7,$8
lui $11,34952
ori $11,$11,34950
sub $10,$10,$11
add $2,$10,$0
jr $0	
nop
