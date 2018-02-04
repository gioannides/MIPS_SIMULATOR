//THIS C PROGRAM WAS TAKEAN FROM: http://www.comp.dit.ie/rlawlor/Alg_DS/sorting/quickSort.c
//WE DID NOT WRITE IT

void quicksort(int number[],int first,int last);
asm("li $sp, 0x23FFFFFC");
int entry()
{
   int i = 8;
   int number[] = {7,4,21,3,-45,23,5678,-9};
   quicksort(number,0,i-1);
   return number[0];
}




void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

