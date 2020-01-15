#include <stdio.h>
#include <string.h>
void reverString(char *string){
  char *revString = string + strlen(string);
  while (revString > string) {
    putchar(* --revString);
      } 
}


int main (){
  char userString[50];
  printf("input a string\n");
  scanf("%s" , userString);
  printf("the reverse String is: ");
  reverString(userString); 
  printf("\n");
  return 0;
}
