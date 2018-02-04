asm("li $sp, 0x23FFFFFC");
int main(){
	char c;
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < 26; i++){
		c = c + alphabet[i];
		c = 16 * c;
		c = c ^ c;
		c = c << 2;
		c = c * c;
		c = c >> 3;
		c = c % 5;
		c = c | 5;
	}
	return c;
}
	
