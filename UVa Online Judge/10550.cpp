#include<stdio.h>


int main()
{
    int a,b,c,d;
    int turn, ans;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)==4)
    {
        if(a==0 && b==0 && c==0 && d==0)
            break;
        ans = 1080;
        if(b>a) ans += (40+a-b)*9;
        else ans += (a-b)*9;
        if(b>c) ans += (40+c-b)*9;
        else ans += (c-b)*9;
        if(d>c) ans += (40+c-d)*9;
        else ans += (c-d)*9;
        printf("%d\n",ans);
    }
    return 0;
}
