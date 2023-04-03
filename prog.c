// included libraries
#include <time.h>
#include <stdio.h>
#include <string.h>

// global variables
enum args{STANDARD, FULL, DATE_ONLY, TIME_ONLY, HELP};
enum months{JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
int CHOICE = 0;

/* Global functions for determing arguments and print date/time */
void SHOW_DATE(int x);
int DETERMINE_ARG(int arg_count, char *arg[]);

/* Global functions for calender */
void PRINT_CALENDAR(int year, int month);
int IS_LEAP_YEAR(int y);
int LEAP_YEARS(int y);
int TODAY_OF(int y, int m, int d);
long DAYS(int y, int m, int d);

int main(int argc, char *argv[]){

    CHOICE = DETERMINE_ARG(argc, argv); // CHOICE get return value from DETERMINE_ARG function
    SHOW_DATE(CHOICE);                  // CHOICE is passed to SHOW_DATE function

    return 0;
}

int DETERMINE_ARG(int arg_count, char *arg[]){

    if (arg_count > 1){ // If we have an argument we will enter the if statement
        if (strcmp(arg[1], "f") == 0 || strcmp(arg[1], "full") == 0) {return FULL;} // f or full = FULL return 1

        else if (strcmp(arg[1], "d") == 0 || strcmp(arg[1], "date") == 0) {return DATE_ONLY;} // d or date = DATE_ONLY return 2

        else if (strcmp(arg[1], "t") == 0 || strcmp(arg[1], "time") == 0) {return TIME_ONLY;} // t or time = TIME_ONLY return 3

        else if (strcmp(arg[1], "h") == 0 || strcmp(arg[1], "help") == 0) {return HELP;} // h or help = HELP return 4

        else {return 4;} // If an invalid argument/option is passed through we go to the determingfault in the switch case in SHOW_DATE function
    }
    else{return STANDARD;} // if no arguments were passed we return 0 for STANDARD
}

void SHOW_DATE(int x){ // CHOICE comes in as x and runs through the switch case
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    switch (x){
        case STANDARD:
            printf("%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            break;
        case FULL:  // with no argument we print FULL, both time, date and calendar
            printf("%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            PRINT_CALENDAR(tm.tm_year + 1900, tm.tm_mon + 1);
            break;
        case TIME_ONLY: // with t as argument we print time only
            printf("%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
            break;
        case DATE_ONLY: // with d as argument we print date only
            printf("%d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
            break;
        case HELP: // with h or help as argument we print list of arguments to chose from
            printf("date command help\n\tOptions:\n\tf or full\tView full time and calendar\n\td or date\tView date only\n\tt or time\tView time only\n\th or help\tView help\n");
            break;
        default: // and if an invalid argument is entered we print the correct arguments
            printf("Invalid argument. Use 'date h' or 'date help' for info.\n");
            break;
    }
}

void PRINT_CALENDAR(int y, int m) /* display calendar at m y */
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Mo Tu We Th Fr Sa Su";
    int DayOfMonth[] =
        { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = DAYS(y, m, 1) % 7;
    if(IS_LEAP_YEAR(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay-1;i++)
        printf("   ");
    for(i=weekOfTopDay-1,day=1;day <= DayOfMonth[m];i++,day++){
        if(day == tm.tm_mday)
            printf("[%d]", day);
        else
            printf("%2d ", day);

        if(i % 7 == 6)
            printf("\n");
    }   
    printf("");
}

// Function to print the calendar of the given year
int IS_LEAP_YEAR(int y) /* True if leap year */
{
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int LEAP_YEARS(int y) /* The number of leap year */
{
    return y/4 - y/100 + y/400;
}

int TODAY_OF(int y, int m, int d) /* The number of days since the beginning of the year */
{
    static int DayOfMonth[] = 
        { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};

    return DayOfMonth[m] + d + ((m>2 && IS_LEAP_YEAR(y))? 1 : 0);
}

long DAYS(int y, int m, int d) /* Total number of days */
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + LEAP_YEARS(lastYear) + TODAY_OF(y,m,d);
}