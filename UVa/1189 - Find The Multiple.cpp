#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>


using namespace std;

#define N		30005
#define ll		long long int
#define fli()	freopen("in.txt", "r", stdin);
#define flo()	freopen("out.txt", "w", stdout);

int n;

int mod(string str)
{
	int rem = 0;
	for (int i = 0; i < (int)str.size(); i++)
	{
		rem = rem * 10 + (str[i] - '0');
		rem %= n;
	}
	return rem;
}

string getMultiple()
{
	string mul = "1";
	queue<string>q;
	q.push(mul);
	while (!q.empty()){
		mul = q.front();
		q.pop();
		if (mul.size() > 100)
			return "false";
		if (mod(mul) == 0)
			return mul;
		q.push(mul + "0");
		q.push(mul + "1");
	}
	return "false";
}


int main()
{
	//fli();
	//flo();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	while (cin >> n){
		if (n == 0)
			break;
		cout << getMultiple() << endl;
	}

	return 0;
}