#include <stdio.h>

int main()
{
    char ch[2000];
    int i;
    while(gets(ch))
    {

        for(i=0;ch[i]!='\0';i++)
        {
        ch[i]=ch[i]-7;
        printf("%c",ch[i]);
        }
        printf("\n");

    }
    return 0;
}
