#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    double x,y,z,temp;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        temp = (x+y)/3;
        x -= temp;
        y -= temp;
        z = z/(x+y);
        //cout<<x*z<<endl;
        printf("%.0lf\n",x*z);
    }
    return 0;
}
