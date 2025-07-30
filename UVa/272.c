#include <stdio.h>

int main()
{
    char ch;
    while(scanf("%c",&ch)==1)
    {
        ch-=7;
        printf("%c",ch);

    }
    return 0;
}
