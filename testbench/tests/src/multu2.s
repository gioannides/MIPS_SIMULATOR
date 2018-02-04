.set noreorder
.set noat


lui $4,0xFFFF
ori $4,$4,0xFFFF
lui $5,0xFFFF
ori $5,$5,0xFFFF
multu $5,$4
mflo $2
jr $0
