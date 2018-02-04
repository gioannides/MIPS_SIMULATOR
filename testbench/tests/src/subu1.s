.set noreorder
.set noat

ori $2,$0,0
ori $4,$0,0
lui $3,0xFFFF
ori $3,$3,0xFFFF
subu $2,$4,$3
subu $2,$2,$3
jr $0
nop			#return 4 , no overflow
