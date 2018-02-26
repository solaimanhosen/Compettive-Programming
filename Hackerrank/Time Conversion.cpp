#include <stdio.h>

using namespace std;

int strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

int main()
{
    char time[15];
    char mode[3];
    int hour, min, sec;

    scanf("%s", time);

    if(strcmp(time, "12:00:00AM") == 0)
        printf("00:00:00\n");
    else if(strcmp(time, "12:00:00PM") == 0)
        printf("12:00:00\n");
    else{
        hour = (time[0]-'0')*10 + time[1]-'0';
        min = (time[3]-'0')*10 + time[4]-'0';
        sec = (time[6]-'0')*10 + time[7]-'0';

        mode[0] += time[8];
        mode[1] = time[9];

        //printf("Mode: %s\n\n", mode);
        if(hour == 12)
            hour = 0;

        if(time[8] == 'P' && time[9] == 'M'){
            hour += 12;
        }

        if(hour < 10)
            printf("0%d:", hour);
        else
            printf("%d:", hour);

        if(min < 10)
            printf("0%d:", min);
        else
            printf("%d:", min);

        if(sec < 10)
            printf("0%d\n", sec);
        else
            printf("%d\n", sec);
    }

    return 0;
}
