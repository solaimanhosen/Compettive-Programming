#include <stdio.h>

int main()
{
    int t, num;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&num);
        num = num*315 + 36962;
        if(num < 0)
            num/= -1;
        num/=10;
        num%=10;
        printf("%d\n",num);
    }
    return 0;
}
