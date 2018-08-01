#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <sstream>

using namespace std;

#define MAX     10006
#define BASE	437
#define M		1000000007
#define ll      long long int
#define fli()   freopen("in.txt", "r", stdin);
#define flo()   freopen("out.txt", "w", stdout);

template<typename T> int toInt(T t){ stringstream ss; ss << t; int r; ss >> r; return r; }

int nextInt(){
	string buffer;
	getline(cin, buffer);
	return toInt(buffer);
}

ll moduleInverse(ll base, ll pow)
{
    if(pow == 0){
        return 1;
    }
    ll x = moduleInverse(base, pow/2);
    x = (x*x)%M;
    if(pow % 2 == 1){
        x = (x*base)%M;
    }
    return x;
}

bool isPalinedrome(string line, int st, int ed)
{
    int f = st;
    int l = ed;
    for(int i = st; i <= (st+ed)/2; i++){
        if(line[f++] != line[l--]){
            return false;
        }
    }
    return true;
}

int solve(string line, int n, int m)
{
    ll hash_left = 0;
    ll hash_right = 0;
    ll pow1 = 1;
    ll pow2 = 1;
    for(int i = m-1; i >= 0; i--){
        hash_left = (hash_left + (line[i]*pow1)%M)%M;
        pow1 = (pow1*BASE)%M;
    }
    for(int i = 0; i < m; i++){
        hash_right = (hash_right + (line[i]*pow2)%M)%M;
        pow2 = (pow2*BASE)%M;
    }
    pow1 = (pow1*moduleInverse(BASE, M-2))%M;
    pow2 = (pow2*moduleInverse(BASE, M-2))%M;
    if(hash_left == hash_right){
        if(isPalinedrome(line, 0, m-1))
            return 1;
    }
    for(int i = m; i < n; i++){
        hash_left = (hash_left - (line[i-m]*pow1)%M);
        hash_left = (hash_left + M)%M;
        hash_left =(hash_left*BASE)%M;
        hash_left = (hash_left + line[i])%M;

        hash_right = (hash_right - line[i-m])%M;
        hash_right = (hash_right+M)%M;
        hash_right = (hash_right*moduleInverse(BASE, M-2))%M;
        hash_right = (hash_right + (line[i]*pow2)%M)%M;
        if(hash_left == hash_right){
            if(isPalinedrome(line, i-m+1, i))
                return 1;
        }
    }
    return -1;
}

int BS(string line, int m)
{
    int low = 1;
    int high = m;
    int mid;
    for(int k = 0; k < 60; k++){
        mid = (low+high)/2;
        if(solve(line, m, mid) != -1){
            low = mid;
        }
        else if(solve(line, m, mid+1) != -1){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    for(int i = min(m, high+2); i >= max(1, low-2) ; i--){
        if(solve(line, m, i) != -1){
            return i;
        }
    }
    return 0;
}

int main()
{
	//fli();
	//flo();

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
    string line;
    cin >> line;
    m = toInt(line);
    cin >> line;
    int res = BS(line, m);
    cout << res << endl;


	return 0;
}