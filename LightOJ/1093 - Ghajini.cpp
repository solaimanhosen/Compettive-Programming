#include <iostream>
#include <stdio.h>

#define N           100005

using namespace std;

struct segment
{
    int max;
    int min;
};

int array[N];
segment tree[4*N];
int n;

void buildTree(int l, int r, int idx)
{
    if(l > r){
        return;
    }
    if(l == r){
        tree[idx].max = tree[idx].min = array[l];
        return;
    }
    int mid = (l+r)>>1;
    int left = idx<<1;
    int right = left+1;

    buildTree(l, mid, left);
    buildTree(mid+1, r, right);

    tree[idx].max = max(tree[left].max, tree[right].max);
    tree[idx].min = min(tree[left].min, tree[right].min);
}

segment query(int l, int r, int s, int e, int idx)
{
    if(l > e || r < s || l > r)
        return {-1000000000, 1000000000};
    if(l >= s && r <= e)
        return tree[idx];
    int mid = (l+r)/2;
    int left = idx<<1;
    int right = left + 1;

    segment leftSegment = query(l, mid, s, e, left);
    segment rightSegment = query(mid+1, r, s, e, right);

    return {max(leftSegment.max, rightSegment.max), min(leftSegment.min, rightSegment.min)};
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, tt, d;
    cin >> tt;
    for(t = 1; t <= tt; t++){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> array[i];
        }
        buildTree(1, n, 1);
        d--;
        int max_diff = -10000000000;
        for(int i = 1; (i+d) <= n; i++){
            segment result = query(1, n, i, i+d, 1);
            max_diff = max(max_diff, result.max-result.min);
        }
        cout << "Case " << t << ": " << max_diff << endl;
    }

    return 0;
}
