#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,w,h,a,b,c,d,n,i;
    while(scanf("%d",&n)==1 && n!=00)
    {
        a=0;
        b=0;
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d",&l,&w,&h);
            if(h>b)
            {
                b=h;
                a=(l*w*h);
            }
            else if(h==b)
            {
                c=(l*w*h);
                if(c>a)
                    a=c;
            }
            else{}
        }
        printf("%d\n",a);
    }
    return 0;
}
