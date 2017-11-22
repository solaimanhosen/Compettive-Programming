#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

string toLower(string str)
{
    for(int i = 0; i < str.length(); i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return str;
}

int main()
{
    char str[105];
    string str1;
    string str2;
    int caseNo = 1, testCase;
    si(testCase);
    getchar();
    while(testCase--)
    {
        str1 = "";
        str2 = "";
        gets(str);
        for(int i = 0; i < strlen(str); i++)
            if(str[i] != ' ') str1 += str[i];

        gets(str);
        for(int i = 0; i < strlen(str); i++)
            if(str[i] != ' ') str2 += str[i];

        str1 = toLower(str1);
        str2 = toLower(str2);
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if(str1 == str2)
            pf("Case %d: Yes\n",caseNo++);
        else
            pf("Case %d: No\n",caseNo++);
    }

    return 0;
}
