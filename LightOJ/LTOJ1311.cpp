#include <bits/stdc++.h>

using namespace std;

int main()
{
    double v1, v2, v3, a1, a2, t1, t2, s1, s2, t;
    int TestCase;

    scanf("%d", &TestCase);

    for(int i = 1; i <= TestCase; i++){
        scanf("%lf%lf%lf%lf%lf", &v1,&v2,&v3,&a1,&a2);

        printf("Case %d: ", i);

        s1 = (v1 * v1) / (2 * a1);
        s2 = (v2 * v2) / (2 * a2);

        t1 = v1 / a1;
        t2 = v2 / a2;

        if(t1 > t2) t = t1;
        else t = t2;

        printf("%lf %lf\n", s1 +s2, v3 * t);

    }

    return 0;
}
