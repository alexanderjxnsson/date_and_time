// included libraries
#include <time.h>
#include <stdio.h>
#include <string.h>

// global variables
//  FULL = no argument from user, DATE_ONLY = -d, TIME_ONLY -t
enum args{FULL, DATE_ONLY, TIME_ONLY};
enum months{JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
int CHOICE = 0;

/* Global functions for daterming arguments and print date/time */
void SHOW_DATE(int x);
int DETERMINE_ARG(int arg_count, char *arg[]);

/* Global functions for calender */
void PRINT_CALENDAR(int year);
int NUMBER_OF_DAYS(int monthNumber, int year);
char* GET_MONTH_NAME(int monthNumber);
int DAY_NUMBER(int day, int month, int year);

int main(int argc, char *argv[]){

    CHOICE = DETERMINE_ARG(argc, argv); // CHOICE get return value from DETERMINE_ARG function
    SHOW_DATE(CHOICE);                  // CHOICE gets sent to SHOW_DATE function

    return 0;
}

int DETERMINE_ARG(int arg_count, char *arg[]){

    if (arg_count > 1){ // If we have more than one argument we will enter the if statement

        if (strcmp(arg[1], "-d") == 0) {return DATE_ONLY;} // -d = DATE_ONLY return 1

        else if (strcmp(arg[1], "-t") == 0) {return TIME_ONLY;} // -t = TIME_ONLY return 2

        else {return 3;} // If an invalid argument/option is passed through we go to the default in the switch case in SHOW_DATE function
    }
    else{return FULL;} // if no arguments were passed we return 0 for FULL
}

void SHOW_DATE(int x){ // CHOICE comes in as x and runs through the switch case
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    switch (x){
        case FULL:  // with no argument we print FULL, both time, date and calendar
            printf("         %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            PRINT_CALENDAR(tm.tm_year + 1900);
            break;
        case TIME_ONLY: // with -t as argument we print time only
            printf("%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
            break;
        case DATE_ONLY: // with -d as argument we print date only
            printf("%d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
            break;
        default: // and if an invalid argument is entered we print the correct arguments
            printf("Enter correct option\n-t\ttime only\n-d\tdate only\n");
            break;
    }
}

// Function that returns the index of the day for date DD/MM/YYYY
int DAY_NUMBER(int day, int month, int year)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4
            - year / 100
            + year / 400
            + t[month - 1] + day-1) // day-1 so we get monday as starting day of the week insted of sunday
           % 7;
}
  
// Function that returns the name of the month for the given month Number
// January - 0, February - 1 and so on
char* GET_MONTH_NAME(int monthNumber)
{
    char* month;
    switch (monthNumber) {
    case 0:     month = "January";      break;
    case 1:     month = "February";     break;
    case 2:     month = "March";        break;
    case 3:     month = "April";        break;
    case 4:     month = "May";          break;
    case 5:     month = "June";         break;
    case 6:     month = "July";         break;
    case 7:     month = "August";       break;
    case 8:     month = "September";    break;
    case 9:     month = "October";      break;
    case 10:    month = "November";     break;
    case 11:    month = "December";     break;
    }
    return month;
}

// Function to return the number of days in a month
int NUMBER_OF_DAYS(int monthNumber, int year){
    if (monthNumber == JANUARY || monthNumber == MARCH || monthNumber == MAY || monthNumber == JULY || monthNumber == AUGUST || monthNumber == OCTOBER || monthNumber == DECEMBER)
    {
        return 31;
    }
    else if (monthNumber == APRIL || monthNumber == JUNE || monthNumber == SEPTEMBER || monthNumber == NOVEMBER)
    {
        return 30;
    }
    if (monthNumber == FEBRUARY) {
        // If the year is leap then Feb has 29 days
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
}
  
// Function to print the calendar of the given year
void PRINT_CALENDAR(int year){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    // Index of the day from 0 to 6
    int current = DAY_NUMBER(1, 1, year);

    int days = NUMBER_OF_DAYS(tm.tm_mon, year);
    // Print the current month name
    printf("  %s\n", GET_MONTH_NAME(tm.tm_mon));

    // Print the columns
    printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

    // j for Iterate through days
    // Print appropriate spaces
    int k;
    for (k = 0; k < current; k++)
        printf("     ");
    int min = 0;

    for (int j = 1; j <= days; j++) {
        if (tm.tm_mday == j && tm.tm_mday <= 9){
            printf("   [%d]", j);
            min = 1;
        }
        else if (tm.tm_mday == j && tm.tm_mday > 9){
            printf("  [%d]", j);
            min = 1;
        }
        else if(min == 1){
            printf("%4d", j);
            min = 0;
        }
        else if(tm.tm_mday < 9){
            printf("%5d", j);
        }
        else{
            printf("%5d", j);
        }

        if (++k > 6) {
            k = 0;
            printf("\n");
        }
    }

    if (k)
        printf("\n");

    current = k;
  
    return;
}