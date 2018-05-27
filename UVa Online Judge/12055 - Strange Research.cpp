#include <bits/stdc++.h>

#define N           1000
#define M           1000
#define ll          long long int
#define fli()       freopen("in.txt", "r", stdin)
#define flo()       freopen("out.txt", "w", stdout)

using namespace std;

struct counter
{
    int freq;
    string low;
    string high;
    counter()
    {
        freq = 0;
        low = high = " ";
    }
};

map <string, counter> mm;

string midSort(char str[])
{
    int len = strlen(str);
    char temp[len+1];
    for(int i = 0; i<len; i++){
        temp[i] = str[i];
    }
    temp[len] = '\0';
    sort(temp+1, temp+(len-1));
    return string(temp);
}

int main()
{
    //fli();
    //flo();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    int len;
    char str[20];
    while(cin >> n)
    {
        mm.clear();
        while(n--){
            cin >> str;
            string ss = midSort(str);
            counter &c = mm[ss];
            if(c.freq == 0){
                c.freq++;
                c.low = c.high = string(str);
            }
            else{
                c.freq++;
                c.low = min(c.low, string(str));
                c.high = max(c.high, string(str));
            }
        }
        cin >> q;
        while(q--){
            cin >> str;
            counter cc = mm[midSort(str)];
            if(cc.freq == 0){
                cout << "0" << endl;
            }else{
                cout << cc.freq << " " << cc.low << " " << cc.high << endl;
            }
        }
    }


    return 0;
}