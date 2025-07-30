#include<stdio.h>

int func(int arr[], int num)
{
    int max, min, i;

    max=arr[0];

    for(i=1; i<num; i++)
        {
            if(max<arr[i])
                max=arr[i];
        }

    min=arr[0];

    for(i=1; i<num; i++)
        {
            if(arr[i]<min)
                min=arr[i];
        }
    return (max-min)*2;
}

int main()
{
    int t,i,j;
    int arr[30];
    int num;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            scanf("%d",&arr[j]);
        }
        printf("%d\n",func(arr,num));
    }

    return 0;
}
