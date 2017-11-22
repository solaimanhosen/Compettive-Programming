#include <bits/stdc++.h>

using namespace std;

int main()
{
    double ox, oy, ax, ay, bx, by, mx, my, ob, om, angle, s, r;

    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%lf%lf%lf%lf%lf%lf", &ox, &oy, &ax, &ay, &bx, &by);
        mx = (ax + bx) / 2;
        my = (ay + by) / 2;
        ob = sqrt((ox - bx)*(ox - bx) + (oy - by)*(oy - by));
        om = sqrt((mx - ox)*(mx - ox) + (my - oy)*(my - oy));
        //cout<<ob<<"  "<<om<<endl;
        angle = acos(om/ob) * 2;
        s = angle * ob;
        printf("Case %d: %.8lf\n", i, s);
    }

    return 0;
}
