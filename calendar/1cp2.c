#include <stdio.h>

void swap(int *num1, int *num2){
  int temp1; 
  temp1 = *num1; 
  *num1 = *num2;
  *num2 = temp1;
}

void bubbleSort(int arr[], int n){
  int i; 
  int j; 
  for (i = 0; i <n-1; i++ ){
    for(j = 0; j < n-1; j++){
      if(arr[j] > arr[j+1]);{
	swap(&arr[j], &arr[j+1]);
}
}
}
}

void printArray(int arr[], int size){
  int i; 
  for (i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
printf("n");
}


int main (int argc, char* argv[]){

  int sizeOfArray;

  printf("enter the size of array\n");
  scanf("%d\n", &sizeOfArray);
  int array[sizeOfArray];
  
  printf("enter the numbers inside the array: \n");
  for(int i = 1; i <= sizeOfArray; i++){
    printf("element - %d: ", i);
    scanf("%d", &array[i-1]);
}

 bubbleSort(int &array[], sizeofArray);
 printf("Sorted array: \n");
 printArray(arr,5);
 return 0;
}
