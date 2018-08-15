#include <iostream>

using namespace std;

#define MAXN    131075

struct Node
{
    int v;
    struct Node* left;
    struct Node* right;
};

int arr1[MAXN];
Node arr[4*MAXN];
Node* root;
int idx;

Node* node()
{
    Node* temp = &arr[idx++];
    temp -> v = 0;
    temp->left = temp->right = 0;
    return temp;
}

void init()
{
    idx = 0;
    root = node();
}

int buildTree(int s, int e, Node* root)
{
    if(s == e){
        root->v = arr1[s];
        return 1;
    }
    int ret1, ret2;
    int mid = (s+e)/2;
    root->left = node();
    root->right = node();
    ret1 = buildTree(s, mid, root->left);
    ret2 = buildTree(mid+1, e, root->right);
    if(ret1 == 1 && ret2 == 1){
        root->v = root->left->v|root->right->v;
        return 2;
    }
    else{
        root->v = root->left->v^root->right->v;
        return 1;
    }
}

int update(int s, int e, Node* root, int index, int val)
{
    if(s == index && e == index){
        root->v=val;
        return 1;
    }
    int ret;
    int mid = (s+e)/2;
    if(index <= mid){
        if(root->left == 0){
            root->left = node();
        }
        ret = update(s, mid, root->left, index, val);
    }else{
        if(root->right == 0){
            root->right = node();
        }
        ret = update(mid+1, e, root->right, index, val);
    }
    if(ret == 1){
        root->v = root->left->v|root->right->v;
        return 2;
    }
    else{
        root->v = root->left->v^root->right->v;
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, pos, val;
    cin >> n >> m;
    init();
    for(int i = 1; i <= (1<<n); i++){
        cin >> arr1[i];
    }
    buildTree(1, 1<<17, root);
    for(int i = 1; i <= m; i++){
        cin >> pos >> val;
        update(1, 1<<17, root, pos, val);
        cout << root->v << endl;
    }


    return 0;
}
