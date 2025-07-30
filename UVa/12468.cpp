#include <stdio.h>

int main()
{
    int num1,num2,c;
    while(scanf("%d%d",&num1,&num2)==2 && num1!=-1 && num2!=-1)
    {
        c=num2-num1;
        if(c<0)
            c= -c;
        if(c>=50)
        c=100-c;
        printf("%d\n",c);
    }
    return 0;
}
