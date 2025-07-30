#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

#define N		30005
#define ll		long long int
#define fli()	freopen("in.txt", "r", stdin);
#define flo()	freopen("out.txt", "w", stdout);

ll palNum[25];

void palGen()
{
	palNum[1] = palNum[2] = 9;
	for (int i = 3; i < 22; i += 2){
		palNum[i] = palNum[i + 1] = palNum[i - 1] * 10;
	}
}

string rev(ll num){
	string str = "";
	while (num != 0){
		str += (num % 10)+'0';
		num /= 10;
	}
	return str;
}


int main()
{
	//fli();
	//flo();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool even;
	palGen();
	ll n;
	while (cin >> n){
		even = false;
		if (n == 0)
			break;
		int digit = 0;
		for (int i = 1; i < 22; i++){
			if (n > palNum[i]){
				n -= palNum[i];
				digit = i;
			}
			else{
				break;
			}
		}
		digit++;
		if (digit % 2 == 0){
			digit /= 2;
			even = true;
		}
		else{
			digit = digit / 2 + 1;
			even = false;
		}
		ll num = 1;
		for (int i = 1; i < digit; i++){
			num *= 10;
		}
		num += (n - 1);
		cout << num;
		if (even){
			cout << rev(num);
		}
		else{
			num /= 10;
			while (num != 0){
				cout << num % 10;
				num /= 10;
			}
		}
		cout << endl;
	}

	return 0;
}