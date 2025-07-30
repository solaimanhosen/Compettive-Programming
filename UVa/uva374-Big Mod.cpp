//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long r, b, p, m;
    while(cin>>b>>p>>m){
        r = (pow(b,p))% m;
        cout<<r<<endl;
    }
    return 0;
}
