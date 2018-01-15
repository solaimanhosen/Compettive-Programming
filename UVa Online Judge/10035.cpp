#include <stdio.h>

int main()
{
    unsigned long int num1,num2,temp;
    int x,y,carry,count;
    while(scanf("%lu%lu",&num1,&num2)==2)
    {
        if(num1==0 && num2==0)
            break;
        if(num1>num2){}
        else
        {
            temp=num1;
            num1=num2;
            num2=temp;
        }
        count=0;carry=0;
        while(num1||num2)
        {
            x=num1%10;num1/=10;
            y=num2%10;num2/=10;
            y+=carry;
            carry=0;
            if(x+y>=10){
                count++;
                carry=1;
            }
        }
        if(count==0)
            printf("No carry operation.\n");
        else if(count==1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",count);
    }
    return 0;
}

