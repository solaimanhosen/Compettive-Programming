#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,sum, element;
    cin >> n;
    sum = 0;
    for(int i = 0; i < n; i++){
        cin >> element;
        sum += element;
    }
    cout << sum << endl;
}
