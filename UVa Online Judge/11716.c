#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int len=0,t,i,j,ck;
    char str[10050];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {

        gets(str);
        len=strlen(str);
        ck=sqrt(len);
        if(pow(ck,2)==len)
        {
            if(len==4)
            {
                printf("%c%c%c%c",str[0],str[2],str[1],str[3]);
            }
            for(j=0;j<len/4;j++)
            {
                printf("%c%c%c%c",str[j].str[j+4],str[j+8],str[j+i,i+4,i+8,i+12)
            }
        }
            printf("%s\n",str);
        else
            printf("INVALID\n");

    }
    return 0;
}
