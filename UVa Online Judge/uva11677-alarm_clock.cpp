#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,m,h1,m1,h2,m2;
    while(cin>>h1>>m1>>h2>>m2 && !(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)){

        h = h2 - h1;
        m = m2 - m1;

        if(m < 0){
            m += 60;
            h--;
        }
        if(h < 0)
            h += 24;

        cout<<h*60+m<<endl;
    }
    return 0;
}
