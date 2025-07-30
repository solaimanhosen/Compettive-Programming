#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct power_geek
{
    int unit;
    int rating;
}data;

bool placement(data x1, data x2)
{
    return x1.rating > x2.rating;
}

int main()
{
    int i, j, n, t;
    long long unit, max_power;
    data var[51];
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        for(j = 1; j <= n; j++)
           scanf("%d %d", &var[j].unit, &var[j].rating);

        sort(var+1, var+n+1, placement);
        max_power = unit = 0;
        for(j = 1; j <= n; j++)
        {
            unit += var[j].unit;
            max_power = max(max_power, unit * var[j].rating);
        }
        printf("Case %d: %lld\n", i, max_power);
    }

    return 0;
}
