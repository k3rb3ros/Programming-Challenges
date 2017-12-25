#include "clock.h"

double degreesBetweenClockHands(int hours, int minutes)
{
    double hour_degrees = 0.0;
    double minute_degrees = 0.0;

    //minute hands are not descrete to hour intervals
    hour_degrees = (((double)hours/12)*360) + (((double)minutes/60)/12)*360;
    hour_degrees = fmod(hour_degrees, 360.0);

    minute_degrees = ((double)minutes/60)*360;
    minute_degrees = fmod(minute_degrees, 360.0);

    //printf("Hour degrees %f, Minute degrees %f\n", hour_degrees, minute_degrees);
 
    return abs(minute_degrees-hour_degrees);
}

int main(void)
{
    int hours = 0;
    int minutes = 0;

    printf("Enter hours \n");
    scanf("%d", &hours);
    hours = hours % 13;

    printf("Enter minutes \n");
    scanf("%d", &minutes);
    if(minutes > 59)
    {
        while(minutes > 59)
        {
            minutes -= 60;
            hours ++;
        }
    }
   
    printf("You entered %d:%d \n", hours, minutes);

    printf("%f degrees between clock hands\n", degreesBetweenClockHands(hours, minutes));
 
    return 0;
}
