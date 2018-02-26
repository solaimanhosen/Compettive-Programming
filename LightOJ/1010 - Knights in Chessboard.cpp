using namespace std;

#include <bits/stdc++.h>
#define sf          scanf
#define pf          printf
#define sfi(a)      sf("%d",&a)
#define sfi2(a,b)   sf("%d %d",&a,&b)



int main()
{
    int t, caseNo = 1, m, n, result, mn;

    sfi(t);
    while(t--){
        sfi2(m,n);

        mn = m * n;
        if(m == 1 || n == 1)
            result = mn;
        else if(m == 2 || n == 2){
            if(m == 2)
                mn = n;
            else
                mn = m;

            if(mn % 4 == 0)
                result = mn;
            if(mn % 4 == 1)
                result = mn + 1;
            if(mn % 4 == 2)
                result = mn + 2;
            if(mn % 4 == 3)
                result = mn + 1;
        }
        else if(mn % 2 == 0)
            result = mn/2;
        else
            result = mn/2+1;

        pf("Case %d: %d\n",caseNo++, result);
    }


    return 0;

}
