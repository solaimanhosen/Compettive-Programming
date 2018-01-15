#include<stdio.h>

int main()
{
    int e,f,c,t,sum,fb,eb,i;
    while(scanf("%d",&t)==1)
    {
        i=1;
        while(i<=t)
        {
            sum=0;
            scanf("%d%d%d",&e,&f,&c);
            eb=e+f;
            while(eb>=c)
            {
                fb=eb/c;
                sum=sum+fb;
                eb=fb+eb%c;
            }
            i++;
            printf("%d\n",sum);
        }
    }
    return 0;
}
