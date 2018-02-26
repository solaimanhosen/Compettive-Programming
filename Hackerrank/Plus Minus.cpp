#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, num;
    double pos, neg, zer;
    pos = neg = zer = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        if(num < 0)
            neg++;
        else if(num > 0)
            pos++;
        else
            zer++;

    }
    cout << pos/n << endl;
    cout << neg/n << endl;
    cout << zer/n << endl;
}


