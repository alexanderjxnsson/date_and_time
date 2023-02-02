#include <stdio.h>
#include <time.h>
 
int main(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("sec: %d\n",tm.tm_sec);
    printf("min: %d\n",tm.tm_min);
    printf("hour: %d\n",tm.tm_hour);
    printf("mday: %d\n",tm.tm_mday);
    printf("mday: %d\n",tm.tm_mon+1);
    printf("year: %d\n",tm.tm_year+1900);
    printf("wday: %d\n",tm.tm_wday);
    printf("yday: %d\n",tm.tm_yday);

}