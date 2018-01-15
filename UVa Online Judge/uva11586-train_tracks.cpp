#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, length;
    char data[200];
    map<char, int> m;

    scanf("%d", &t);
    getchar();
    while(t--){
        gets(data);
        m.clear();
        length = strlen(data);

        if(length > 3){
            for(i = 0; i< length; i++)
                m[data[i]]++;

            if(m['F'] == m['M']) printf("LOOP\n");
            else printf("NO LOOP\n");
        }
        else printf("NO LOOP\n");
    }


    return 0;
}
