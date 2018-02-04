int calcTester(int n);
asm("li $sp, 0x23FFFFFC");

int entry(){
	int n = 5;
	return calcTester(n);
}

int calcTester(int n){
	n = n * 5;
	n = n / 4;
 	n = n % 3;
	n = n + 23452345;
	n = n | 4;
	n = n & 1234234;
	n = n ^ 573983475;
	n = n % 256;
	return n;
}
