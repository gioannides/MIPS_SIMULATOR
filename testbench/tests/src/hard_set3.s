.set noat
.set noreorder

main:	add $6,$0,$0
	beq $6,$0, label2
	nop
label1: addi $6,$6,7
label2: addi $6,$6,1
	addi $7,$0,-1
	bgez $7, label4
	nop
label3: addi $6,$6,-10
label4: addi $6,$6, 11
	bltz $7, label6
	nop
label5: add $6,$6,13
label6: addi $6,$6,1
	add $8,$0,$0
	blez $8, label7
	nop
	addi $6,$6,17
label7: bgtz $8,label8		
	nop
	addi $6,$6,-14
label8: addi $6,$6,16
	addi $2,$6,0
	jr $0	
	nop		
