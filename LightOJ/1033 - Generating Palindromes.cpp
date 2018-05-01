#include <iostream>
#include <string>

using namespace std;

#define N		101

int dp[N][N];
string str;

int min(int a, int b)
{
	if (a <= b)
		return a;
	return b;
}

int solve(int l, int r)
{
	if (dp[l][r] == -1){
		if (l >= r){
			return dp[l][r] = 0;
		}
		else if (str[l] == str[r]){
			dp[l][r] = solve(l + 1, r - 1);
			return dp[l][r];
		}
		else{
			dp[l][r] = min(1 + solve(l + 1, r), 1 + solve(l, r - 1));
			return dp[l][r];
		}
	}
	return dp[l][r];
}

void init()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			dp[i][j] = -1;
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t, strLength;
	cin >> t;
	for (int testCase = 1; testCase <= t; testCase++){
		init();
		cout << "Case " << testCase << ": ";
		cin >> str;
		strLength = str.size();
		cout << solve(0, strLength - 1) << endl;
	}


	return 0;
}