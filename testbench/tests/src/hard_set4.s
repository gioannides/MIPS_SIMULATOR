.set noat
.set noreorder


add $1,$0,$0
addi $3,$0,-10			
addi $4,$0,20			
slt $5,$3,$4			
add $1,$1,$5			
sltu $7,$3,$4		
add $1,$1,$7			
slti $6,$3,-5			
add $1,$1,$6			
add $1,$1,$1
sltiu $8,$3,-5		
add $1,$1,$8			
add $1,$1,$1			
addi $2,$1,0
jr $0	
nop		 
