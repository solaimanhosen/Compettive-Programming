#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2;
    map <string, int > mon, day;
    mon["JAN"] = 31;
    mon["FEB"] = 28;
    mon["MAR"] = 31;
    mon["APR"] = 30;
    mon["MAY"] = 31;
    mon["JUN"] = 30;
    mon["JUL"] = 31;
    mon["AUG"] = 31;
    mon["SEP"] = 30;
    mon["OCT"] = 31;
    mon["NOV"] = 30;
    mon["DEC"] = 31;
    day["SUN"] = 1;
    day["MON"] = 2;
    day["TUE"] = 3;
    day["WED"] = 4;
    day["THU"] = 5;
    day["FRI"] = 6;
    day["SAT"] = 7;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> str1 >> str2;
        int ans = 0, days;
        days = day[str2];
        for(int i = 1; i <= mon[str1]; i++)
        {
            if(days == 6 || days == 7)
                ans++;
            if(days == 7)
                days = 0;
            days++;
        }
        cout << ans << endl;
    }
    return 0;
}
