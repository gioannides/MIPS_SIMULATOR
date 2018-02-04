.set noreorder

	li $3,0
	li $4,0xFFFFFFF
	mtlo $4
	div $3,$4
	mflo $2
	jr $0			#return 0
	nop
