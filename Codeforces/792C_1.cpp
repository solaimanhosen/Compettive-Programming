#include <iostream>
#include <string>
using namespace std;

string k, r, t;

int c(string k)
{
    int a = 0;
    for (int i = 0; i < k.length(); ++i)
        a = (a + k[i] - '0') % 3;
    return a | !k.length();
}

void b(string &t)
{
    while (t[0] == '0' && t.length() > 1)t.erase(0, 1);
}

int main()
{
    cin >> k;
    int a = c(k), y = 3 - a, q = 1, w = 2;
    r = t = k;
    for (int i = k.length() - 1; i >= 0; --i)
    {
        if ((k[i] - '0') % 3 == a && q)r.erase(i, 1), q = 0;
        if ((k[i] - '0') % 3 == y && w)t.erase(i, 1), --w;
    }
    q = c(t), w = c(r), b(t), b(r);
    if (q && w)r = "-1";
    else if (t.length() > r.length() && !q || w)r = t;
    cout << r;
}
