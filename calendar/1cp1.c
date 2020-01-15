#include <stdio.h>



void swap(int *num1, int *num2, int *num3){

  printf("the values you entered are: \n%d,%d,%d", *num1, *num2, *num3);
  int temp1;  
  temp1 = *num1;
  *num1 = *num2;
  *num2 = *num3;
  *num3 = temp1;
  printf("\nThe swapped values are: \n%d,%d,%d\n", *num1, *num2, *num3);
}



int main (int argc, char* argv[]){
int a;
int b; 
int c;

 printf("Enter first number \n");
 scanf("%d",&a );
 printf("Enter second number \n");
 scanf("%d",&b );
 printf("Enter thrid number \n");
 scanf("%d",&c );
 swap(&a, &b, &c);
}

