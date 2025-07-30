#include <stdio.h>

int main()
{
    int num,sum,i;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&num)==1 && num!=0)
    {
        sum=0;
        for(i=1; i<=num/2; i++)
        {
            if(num%i==0)
            {
                sum=sum+i;
            }
        }
        if(num==sum)
            printf("%5d  PERFECT\n",num);
        else if(num>sum)
            printf("%5d  DEFICIENT\n",num);
        else
            printf("%5d  ABUNDANT\n",num);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
