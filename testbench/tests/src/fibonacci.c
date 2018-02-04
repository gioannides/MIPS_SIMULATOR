int Fibonacci(int);
asm("li $sp, 0x23FFFFFC");
 
int main()
{
   int n = 8;
 
   return Fibonacci(n);
}
 
int Fibonacci(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
} 
