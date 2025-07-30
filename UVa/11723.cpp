#include <stdio.h>

int main()
{
    int r,n,num,i=1;
    while(scanf("%d%d",&r,&n)==2)
    {
        if(r==0 && n==0)
            break;
        num=(r-1)/n;

        if(num<=26)
            printf("Case %d: %d\n",i++,num);
        else
            printf("Case %d: impossible\n",i++);
    }
    return 0;
}
