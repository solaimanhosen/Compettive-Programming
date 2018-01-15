#include <stdio.h>

int main()
{
    int num,t,i,n,rem,count[11];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        for(i=0;i<10;i++)
            count[i]=0;
        for(i=1;i<=num;i++)
        {
            n=i;
            while(n!=0)
            {
                rem=n%10;
                n/=10;
                if(rem==0)
                    count[0]++;
                else if(rem==1)
                    count[1]++;
                else if(rem==2)
                    count[2]++;
                else if(rem==3)
                    count[3]++;
                else if(rem==4)
                    count[4]++;
                else if(rem==5)
                    count[5]++;
                else if(rem==6)
                    count[6]++;
                else if(rem==7)
                    count[7]++;
                else if(rem==8)
                    count[8]++;
                else if(rem==9)
                    count[9]++;

            }
        }
        for(i=0;i<10;i++){
            printf("%d",count[i]);
            if(i<9)
                printf(" ");
        }
        printf("\n");
    }
}
