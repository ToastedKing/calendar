CAL(1)                         MCS-284 Commands Manual                     CAL(1)

NAME
     cal - displays a calendar

SYNOPSIS
     cal
     cal month year
     cal -m month year

DESCRIPTION
     The cal will display a calander for a month and year determind by the user

     The options are as follows:
    "nothing"
		Displays the calendar for current month and year
	no parameters are given. will get current year and month from system

     year
		Displays the calendar of a given year
	1 parameter given by user. gets users year and displays the calendar for that year
	Note: does not work
	
     -m month
             Display the users mont and current year

 	2 parametes given by user. -m will be checked. Then the program will get
	current year and then get the users month. Program will also find if the parameter
	is a char or int. 
     
    -m month and year
		Display the users month and year
	3 parametes given by user. -m will be checked. Then the program will get
	year and month from user. Program will also find if the parameter
	is a char or int. 

     A year starts on January 1.


AUTHORS
     bayalave@gustavs.edu

BUGS
     argv can not be made into a char string. can not dispaly a cal from a 
     char argv. however the test cases given a char will work.
     argv is the only problem i have in this program

MCS-284                           oct 1, 2018                          MCS-284