#include <iostream>
#include <string>
#define ll long long int
 
using namespace std;
 
ll q;
 
ll zeros(ll num)
{
    ll counter = 0;
    while (num > 0){
        num /= 5;
        counter += num;
    }
    return counter;
}
 
ll BinarySearch(int q)
{
    ll low = 0;
    ll high = 10000000000000;
    ll count = 0, mid = 0;
    while (low <= high){
        mid = (low + high) / 2;
        //cout << low << " " << high << " " << mid << endl;
        count = zeros(mid);
        if (count > q){
            high = mid - 1;
        }
        else if (count < q){
            low = mid + 1;
        }
        else{
            while (zeros(mid) == q){
                mid--;
            }
            mid++;
            break;
        }
    }
    if (zeros(mid) == q)
        return (int)mid;
    return -1;
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++){
       
        cin >> q;
        cout << "Case " << testCase << ": ";
        ll ans = BinarySearch(q);
        if (ans == -1){
            cout << "impossible" << endl;
        }
        else{
            cout << ans << endl;
        }
    }
 
 
    return 0;
}
