#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// global variables used throught 
int currentYear = 0; 
int currentMonth = 0;

int dayList[] = {31,28,31,30,31,30,31,31,30,31,30,31};

char *monthList[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *shortMonthList[] = {"jan", "feb","Mar","Apr","May","jun","jul","aug","oct","nov","dec"};

int dayCount = 0; 

void  dayCounter(int year){ // finds the day count for the year
  int i; 
  for(i = 1753 ; i < year ; i ++){ // counts the days in a regular year
    if (isLeapYear(i) == 1){
      dayCount = dayCount + 366;
    }
    else{
      dayCount =  dayCount + 365; // counts the days of a leap year
    }
  }
  
}// ends dayCounter

int dayOfWeek(int year, int month){ // finds the day of the week
  dayCounter(year);
  int i;
  for (i  = month; i > 0 ; i--){ // checks every month
    isLeapYear(year);
    dayCount = dayCount +  dayList[i - 2]; // adds month's day
  }
  dayCount = dayCount + 1; // adds 1 day
  
   return (dayCount % 7); // returns day of week
}

int isLeapYear(int year){ // checks if year is a leap year
  if( (year%100) == 0){ // year is div by 100 so it is NOT a leap year
    if((year % 400) == 0){ // year is div by 400 and 100 so it is a leap year      
      dayList[1] = 29;
      return 1;
    }
    else {
      dayList[1] = 28;
      return 0;
    }  
  } 
  if ((year %4) == 0){ // year is div by 4 so it is a leap year    
    dayList[1] = 29;
    return 1; 
  }
  else {
    dayList[1] = 28;
    return 0; // does not meat any requirments so it is NOT a leap year. 
  }
}
void setMonthCenter ( int month, int year){ //prints and centers month.  
  
  int center = (20 - strlen(monthList[month - 1]) - 4 ) / 2; // creats spaces to center a month
  printf("%*c" , center, ' '); // prints spaces before a month
  printf("%s %d\n", monthList[month - 1] , year); // prints centered month
}

int checkDate( int month, int year){ // checks to see if it is a valid day
  if ( (year < 1753) || ((month < 0) || (month > 12))) // checks bounds of month and year
    {
      return 0; 
    }
  else {
    return 1;
  }
}

void changeString(char *stringMonth){ // changes string to lower case
  int i = 0;
  while(stringMonth[i] != '\0'){ // runs when the array is not empty
    if(stringMonth[i]>= 'A' && stringMonth[i] <= 'Z'){ // checks A - Z 
      stringMonth[i] = stringMonth[i] + 32;  // checks slot of bits then moves over to a lower case. (+ 32)
    }
    i++; 
  }
}

int  checkMonth(char *lowerCaseMonth[], char userMonth[]){ // checks users input and set it to a month 
  changeString(userMonth);
  
  int i;
  for(i = 0; i < 12; i ++){ // checks all months
    if (strncmp(userMonth, lowerCaseMonth[i], 3) == 0){ // checks first 3 characters and compares them. 
      return i + 2; // returns month
    }
  }
  printf("Not a valid month\n"); // may be for bad input
  return 0; // ends check
}

void printMonth(int month, int year){
  if(checkDate(month, year) == 0 ) // checks if its a vaid date
    {
      printf("not a valid date\n");
    }
  else {
    int emptySpace =dayOfWeek(year, month); // creats an intger storing the number of empty days needed
    
    setMonthCenter(month, year); // centers month
    printf("Su Mo Tu We Th Fr Sa\n"); // prints the week title
    printf("%*c", (emptySpace * 3), ' ');    // prints the number of spaces needed
    int i;
    for (i = 1; i <= dayList[month - 1]; i++){
      if (i == 1) { // selects char slot from the first day it starts on
	printf("%2d", i );
      }
      else if ((i + emptySpace) % 7 == 1){ // when day starts on sunday
	printf("%2d", i);
      }
      else { // prints a normal day
	printf("%3d", i);
      }
      if ((i + emptySpace) % 7 == 0){ // if day starts on saturday will return a new line
	printf("\n");
      }
    }
    printf("\n");
  }
}

void printYear(int year){ // prints a year's worth of months
  int i;
  while (i < 12){
  printMonth(i, year);
  i ++;
  }
}


void currentDate(int *month, int *year){ // gets systms current month and year 
  time_t timenow;  //creats an object of time
  struct tm *current; // creates a struckt
  time(&timenow); // finds current time
  current = gmtime(&timenow);  // gets current time
  *month = current -> tm_mon + 1;  // stores month
  *year = current -> tm_year+1900; // stores year
}

int main (int argc, char* argv[]){ // runs program
  currentDate(&currentMonth, &currentYear); // assignes current month and year
  switch (argc){ // able to decide how many parameters the user is using
    
  case 1: // no parmaters are given
    printMonth(currentMonth, currentYear); // prints the current year and month
    return 0;
  case 2: // 1 parameter given
    // bouns does not work
    if(strcmp(argv[1], "-m") == 0){ // checks if there is a -m in the parameter
      printf("invalid");
      return 0;
    }  
    else {
    int  year = atoi(argv[1]); 
    printYear(year);
    return 0;
      }
  case 3:
    // will take in 2 aguments. then use if, else to see what kind of parameters are being used
    if(strcmp(argv[1], "-m") == 0){ // checks if there is a -m in the parameter
      int month = atoi(argv[2]); // gets a month from the user
      printMonth(month, currentYear); // prints mon and current year
      return 0;
    }  
    else if (atoi(argv[1]) == 0){ // checks to see if there is a char parameter
      int mon = checkMonth(shortMonthList, argv[1]);  // gets char paratmer and short month and compares if they are the same
      int year = atoi(argv[2]);	 // gets year from the user
      
      printMonth(mon, year);  // prints month and year
      return 0; 
    }  
    else { // there is no -m with 2 integer parameters
      int month = atoi(argv[1]);  // gets month from uesr
      int year = atoi(argv[2]); // gets year from user
      printMonth(month, year); // prints month and year
      return 0;
    }
    return 0;
  case 4: // 3 parameters given
    if (atoi(argv[2]) == 0) { // chcecks to see if there is a char parameter
      if(strncmp(argv[1],"-m",2)  == 0){ // checks to see if there is a -m
	int month = (checkMonth(shortMonthList, argv[2])); // gets a month from the parameter
	int year = atoi(argv[3]); // gets a year from user
	printMonth(month,year); // prints month and year
	return 0; 
      }   
      else {
	printf("not a valid input"); // if char parameter does not match 
	return 0; 
      }
    }
    else {
      if(strncmp(argv[1],"-m",2) == 0){ // checks to see if parameter has a -m
	int month = atoi(argv[2]); // gets month from user
	int year = atoi(argv[3]); // gets a year from uesr
	printMonth(month, year); // prints month and year
	return 0;
      }
    }
  default: 
    printf("not a vaid input"); // message user if they put in worng inputs
    return 0;
    
  }// end swtich 
  return 0;
} // end main
