#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num, g, d, i, j;
    string str;
    vector <string> v;
    map <string , int> m;

    cin>>num;
    while(true){
        v.clear();
        m.clear();
        for(i = 0; i < num; i++){
            cin>> str;
            v.push_back(str);
        }
        for(i = 0; i < num; i++){
            cin>>str>>g>>d;
            if(d != 0){
                m[str] -= d*(g/d);
                for(j = 0; j< d; j++){
                    cin>>str;
                    m[str] += g/d;
                }
            }
        }
        for(i = 0; i< num; i++){
            cout<<v[i]<<" "<<m[v[i]]<<endl;
        }
        if(cin>>num) cout<<endl;
        else break;
    }
    return  0;
}
