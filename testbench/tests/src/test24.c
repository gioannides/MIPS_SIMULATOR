int fact(int n);

asm("lui $sp, 0x23FF");
asm("ori $sp, $sp, 0xFFFC");

int entry(){

	int n = 8;
	return fact(n);
}


int fact(int n){
	if(n > 1)
		return n * fact(n - 1);
	else
		return 1;
}

