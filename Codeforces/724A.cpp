#include <bits/stdc++.h>

using namespace std;

int main()
{
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    map <string, int > m;
    m["monday"] = 1;
    m["tuesday"] = 2;
    m["wednesday"] = 3;
    m["thursday"] = 4;
    m["friday"] = 5;
    m["saturday"] = 6;
    m["sunday"] = 7;

    string str1, str2;



    while(cin >> str1 >> str2)
    {
        bool res = false;
        for(int i = 0; i < 11; i++)
        {
            if(m[str1] + (month[i] % 7) > 7)
            {
                if(((m[str1] + (month[i] % 7)) % 7) == m[str2])
                {
                    cout << "YES" <<endl;
                    res = true;
                    break;
                }

            }
            else
            {
                    if((m[str1] + (month[i] % 7)) == m[str2])
                    {
                        cout << "YES" <<endl;
                        res = true;
                        break;
                    }
            }
        }
        if(!res)
            cout << "NO" << endl;
    }

    return 0;
}
