#include<stdio.h>



int Dif(int a,int b)
{
    if(a>=b)
        return a-b;
    else
        return b-a;
}



int main ()
{
    int num,i,j,input[3002],aray[3002],count=0,size,sort_help;

    while(scanf("%d",&num)==1)
    {
        for(i=0; i<num; i++)
        {
            input[i]=0;
            scanf("%d",&input[i]);
        }
        if(num==1)
        {
            printf("Jolly\n");
        }
        else
        {
            size=num-1;
            for(i=0; i<num-1; i++)
                aray[i]=Dif(input[i],input[i+1]);
            if(num==2 && aray[0]==1)
            {
                printf("Jolly\n");
            }
            else
            {
                size=num-2;
                for(j=1; j<=num-2; j++)
                {
                    for(i=0; i<size; i++)
                    {
                        if(aray[i]<aray[i+1])
                        {
                            sort_help=aray[i];
                            aray[i]=aray[i+1];
                            aray[i+1]=sort_help;
                        }
                    }
                    size--;
                }
                count=0;
                for(i=0; i<num-2; i++)
                {
                    if(aray[i]-aray[i+1]==1)
                        count++;
                }

                if(count==num-2)
                    printf("Jolly\n");
                else
                    printf("Not jolly\n");
            }

        }
    }

    return 0;
}



