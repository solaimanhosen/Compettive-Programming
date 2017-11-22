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
#define N           100005

string str[N+5];

struct node
{
    bool endmark;
    node* next[10];
    node(){
        endmark = false;
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }
};

struct node* root;

bool comp(string str1, string str2)
{
    if(str1.length() == str2.length())
        return (str1 < str2);
    return (str1.length() < str2.length());
}

int insertString(string str)
{
    node* curr;
    curr = root;
    int id;
    for(int i = 0; i < str.length(); i++){
        id = str[i] - '0';
        if(curr -> next[id] == NULL){
            curr -> next[id] = new node();
        }
        curr = curr -> next[id];
        if(curr -> endmark)
            return 0;
    }
    curr -> endmark = true;
    return 1;
}

void del(node* root)
{
    for(int i = 0; i < 10; i++){
        if(root -> next[i] != NULL)
            del(root -> next[i]);
    }
    delete root;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n, caseNo = 1, result;
    cin >> t;
    while(t--){
            pfc(caseNo++);
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> str[i];
        }
        sort(str, str+n, comp);

        result = 1;
        root = new node();

        for(int i = 0; i < n && result; i++){
            result = insertString(str[i]);
        }
        del(root);
        if(result)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}


