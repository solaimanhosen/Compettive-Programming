using namespace std;
#include <bits/stdc++.h>

#define pf          printf
#define sf          scanf
#define si(x)       sf("%d",&x)
#define si2(x,y)    sf("%d %d",&x,&y)
#define si3(x,y,z)  sf("%d %d %d",&x,&y,&z)
#define ss(x)       sf("%s",x)
#define pfc(x)      pf("Case %d: ",x)
#define pfcn(x)     pf("Case %d:\n",x)
#define pfv(x)      pf("%d\n",x)
#define pb          push_back
#define ll          long long
#define f           first
#define s           second
#define N           10005

string str[N+5];

class node
{
    bool endmark;
    node* next[10];
public:
    node(){
        endmark = false;
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }
    bool insertSignal(string sig, int pos)
    {
        if(endmark)
            return false;
        if(pos == sig.length())
            return endmark = true;
        int id = sig[pos] - '0';
        if(next[id] == NULL)
            next[id] = new node();
        return next[id]->insertSignal(sig,++pos);
    }
    void del()
    {
        for(int i = 0; i <10; i++){
            if(next[i] != NULL){
                next[i]->del();
                delete next[i];
            }
        }
    }
};

node* root;

bool comp(string str1, string str2)
{
    if(str1.length() == str2.length())
        return (str1 < str2);
    return (str1.length() < str2.length());
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n, caseNo = 1, result;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> str[i];
        }
        sort(str, str+n, comp);

        result = 1;
        root = new node();

        for(int i = 0; i < n && result; i++){
            result = root->insertSignal(str[i], 0);
        }
        root->del();
        delete root;
        pfc(caseNo++);
        if(result)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}



