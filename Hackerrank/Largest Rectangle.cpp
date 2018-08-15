#include <iostream>
#include <stack>

using namespace std;

#define MAXN        100005
#define ll          long long int

ll arr[MAXN];
int n;

ll maxAreaRectangle()
{
    stack<int>st;
    ll maxArea = -1;
    ll area;
    ll i = 1;
    ll top;
    while(i <= n){
        if(st.empty() || arr[st.top()] <= arr[i]){
            st.push(i++);
        }else{
            top = st.top();
            st.pop();
            if(st.empty()){
                area = arr[top]*(i-1);
            }else{
                area = arr[top]*(i - st.top()-1);
            }
            maxArea = max(maxArea, area);
        }
    }
    while(!st.empty()){
        top = st.top();
        st.pop();
        if(st.empty()){
            area = arr[top]*(i-1);
        }else{
            area = arr[top]*(i - st.top()-1);
        }
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    cout << maxAreaRectangle() << endl;

    return 0;
}
