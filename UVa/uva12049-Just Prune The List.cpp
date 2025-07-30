#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arry1[10005], arry2[10005], t, m, n, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < n; i++)
            cin >> arry1[i];
        for(i = 0; i < m; i++)
            cin >> arry2[i];
        sort(arry1, arry1+n);
        sort(arry2, arry2+m);
        int cnt = i = j = 0;
        while(i < n && j < m)
        {
            if(arry1[i] == arry2[j])
            {
                i++;j++;
            }
            else if(arry1[i] > arry2[j])
            {
                j++;cnt++;
            }
            else
            {
                i++;cnt++;
            }
        }
        cout << cnt+(n-i)+(m-j) << endl;
    }


    return 0;
}
