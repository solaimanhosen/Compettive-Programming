#include<stdio.h>

int main()
{
    int i, j, k, arr[25][3], num, total;
    long long int sum;

    scanf("%d", &total);

    for(i=0; i<total; i++)
        {
            scanf("%d", &num);
            for(j=0; j<num; j++)
                {
                    for(k=0; k<3; k++)
                        {
                            scanf("%d", &arr[j][k]);
                        }
                }

            sum=0;
            for(j=0; j<num; j++)
                {
                    sum=sum+(arr[j][0]*arr[j][2]);
                }

            printf("%lld\n", sum);
        }

    return 0;
}
