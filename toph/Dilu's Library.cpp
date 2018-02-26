#include<bits/stdc++.h>
#define ll long long int
#define pf printf

using namespace std;

int main()
{
    ll test, a, b, temp,x,y,ara[105],i,c,d;
    scanf("%lld", &test);
    while(test--)
    {
        scanf("%lld %lld", &a, &b);
        temp=(ll)(a/b);
        //pf("%lld", temp);
        a=a%b;
        x=0;
        int e=0;
        if(a>0)
        {
            e=1;
            //pf(".");
            for(i=1; i<=100; i++)
            {
                if(a==0)
                {
                    break;
                }
                //pf("%lld\n", ((a*10)/b));
                ara[i]=(a*10)/b;
                a=(a*10)%b;
                d=i;
            }
            ll v=(a*10)/b;
            //pf("i=%lld v=%lld %lld\n",i,v,ara[i-1]);
            if(i==101 && v>=5)
            {
                x=1;
                //d++;
                ara[i]=v;
                i--;
                while(i>0)
                {
                    ara[i]++;
                    c=(ara[i]/10);
                    ara[i]%=10;
                    if(c==0)
                    {
                        x=0;
                        break;
                    }
                    i--;
                }
                if(x==1)
                    temp++;
            }
            else if(v>0)
            {
                //d++;
                ara[i]=v;
            }
        }
        pf("%lld",temp);
        if(e==1)
        {
            //pf("%lld\n",d);
            while(1)
            {
                if(ara[d]>0)
                    break;
                d--;
            }
            if(d>0)
                pf(".");
            for(i=1; i<=d; i++)
                pf("%lld",ara[i]);
        }
        //pf("%lld", round((a*10)/b));
        pf("\n");
    }

    return 0;
}
