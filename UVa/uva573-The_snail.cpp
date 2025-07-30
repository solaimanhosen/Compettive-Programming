#include <bits/stdc++.h>

using namespace std;

int main()
{
    double h, u, d, f, day, sum;
    bool result ;

    while(scanf("%lf%lf%lf%lf", &h, &u, &d, &f) == 4 && h){
        sum = 0;
        day = 0;
        f = u*(f/100.0);
        result = true;

        while(result){
            day++;
            if(u > 0) sum += u;
            u -= f;
            if(sum > h) result = false;
            sum -= d;
            if(sum < 0) result = false;
        }
        if(sum < 0) printf("failure on day %.0lf\n", day);
        else printf("success on day %.0lf\n", day);
    }



    return 0;
}
