#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, len, i;
    char data[130];

    scanf("%d", &t);
    getchar();
    while(t--){
        gets(data);

        len = strlen(data);
        stack<char>stk;

        for(i = 0; i< len; i++){
            if(!stk.empty() && data[i] == ')' && stk.top() == '(')
                stk.pop();
            else if(!stk.empty() && data[i] == ']' && stk.top() == '[')
                stk.pop();
            else
                stk.push(data[i]);
        }

        if(stk.empty()) printf("Yes\n");
        else printf("No\n");
    }

    return 0;

}
