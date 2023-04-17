
enum args{STANDARD, FULL, DATE_ONLY, TIME_ONLY, HELP};
enum months{JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
enum day_of_week{SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
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
void IS_SWE_HOLIDAY();
