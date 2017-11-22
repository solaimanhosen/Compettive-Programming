#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int toNum(string str)
{
    int i, j, num = 0;
    reverse(str.begin(), str.end());
    j = 1;
    for(i = 0; i < str.length(); i++)
    {
        if(str[i] == '1')
        {
            num += j;
        }
        j *= 2;
    }
    //cout << num<< endl;
    return num;
}

int main()
{
    int t, caseNo = 1, i, j, index;
    string str1, str2, fstr[4], sstr[4];
    si(t);
    while(t--)
    {
        cin >> str1 >> str2;
        index = j = 0;
        fstr[j] = "";
        for(i = 0; i < str1.length(); i++)
        {
            if(str1[i]!='.')
                fstr[j] += str1[i];
            else
            {
                j++;
                index = 0;
                fstr[j] = "";
            }

        }
        index = j = 0;
        sstr[j] = "";
        for(i = 0; i < str2.length(); i++)
        {
            if(str2[i]!='.')
                sstr[j] += str2[i];
            else
            {
                j++;
                index = 0;
                sstr[j] = "";
            }

        }
        bool result = true;
        for(i = 0; i < 4; i++)
            if(atoi(fstr[i].c_str()) != toNum(sstr[i]))
            {
                result = false;
                break;
            }
        if(result)
            pf("Case %d: Yes\n", caseNo++);
        else
            pf("Case %d: No\n", caseNo++);
    }

    return 0;
}

