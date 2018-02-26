#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int main()
{
    int max_jump ,curr_jump;
    char ch[105];
    max_jump = curr_jump = 1;
    scanf("%s", ch);
    for(int i = 0; i < strlen(ch); i++)
    {
        if(ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U'||ch[i]=='Y')
        {
            max_jump = max(max_jump, curr_jump);
            curr_jump = 1;
        }
        else
            curr_jump++;
    }
    max_jump = max(max_jump, curr_jump);
    printf("%d\n", max_jump);

    return 0;
}

