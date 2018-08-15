#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <sstream>
 
using namespace std;
 
#define MAX     10006
#define BASE    257
#define M       1000000007
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
 
void solve(string line)
{
    ll hash_left = 0;
    ll hash_right = 0;
    ll pow1 = 1;
    ll pow2 = 1;
    int m = line.length();
    for(int i = m-1; i >= 0; i--){
        hash_left = (hash_left + (line[i]*pow1)%M)%M;
        pow1 = (pow1*BASE)%M;
    }
    for(int i = 0; i < m; i++){
        hash_right = (hash_right + (line[i]*pow2)%M)%M;
        pow2 = (pow2*BASE)%M;
    }
    string add = "";
    int i = -1;
    pow1 = (pow1*moduleInverse(BASE, M-2))%M;
    while(hash_left != hash_right && ++i < m){
        add += line[i];
        hash_left = (hash_left - (line[i]*pow1)%M);
        hash_left = (hash_left + M)%M;
        pow1 = (pow1*moduleInverse(BASE, M-2))%M;
 
        hash_right = (hash_right - line[i])%M;
        hash_right = (hash_right+M)%M;
        hash_right = (hash_right*moduleInverse(BASE, M-2))%M;
    }
    cout << line.length() + add.length() << endl;
}
 
int main()
{
    //fli();
    //flo();
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string word;
    string line;
    int t, caseNo = 1, n, m;
    t = nextInt();
    while (t--){
        getline(cin, line);
        cout << "Case " << caseNo++ << ": ";
        solve(line);
    }
 
 
 
 
    return 0;
}