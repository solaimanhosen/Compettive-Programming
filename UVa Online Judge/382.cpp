#include <stdio.h>

int main()
{
    int num,sum,i;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&num)==1)
    {

        if(num==0)
        {
            break;
        }
        else
        {
            sum=0;
            for(i=1;i<=num/2;i++)
            {
                if(num%i==0){
                    sum=sum+i;
                }
            }
            if(num==sum)
                printf("     %d  %s\n","PERFECT");
            else if(num>sum)
                printf("     %d  %s\n","DEFICIENT");
            else
                printf("     %d  %s\n","ABUNDANT");
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
