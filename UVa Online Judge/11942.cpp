#include <stdio.h>

int main()
{
    int t,num[30],i,count1,count2;
    printf("Lumberjacks:\n");
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<10;i++)
        {
            scanf("%d",&num[i]);
        }
        count1=0,count2=0;
        for(i=0;i<9;i++)
        {
            if((count1==0 && count2==i) || (count1==i && count2==0))
            {
            if(num[i]>num[i+1])
                count1++;
            if(num[i]<num[i+1])
                count2++;
            }
            else
                break;
        }
        if(count1==i || count2==i)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
}
