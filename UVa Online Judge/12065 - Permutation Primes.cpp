#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

//#define debug

#define MAX 16
#define PRIME_LIMIT			1100

int primeList[2000];
bool mark[2000];
int idx;

void seive()
{
	int i, j;
	idx = 0;
	primeList[idx++] = 2;

	for (i = 4; i <= PRIME_LIMIT; i += 2){
		mark[i] = true;
	}

	for (i = 3; i*i <= PRIME_LIMIT; i += 2){
		if (!mark[i]){
			for (j = i + i; j <= PRIME_LIMIT; j += i){
				mark[j] = true;
			}
			primeList[idx++] = i;
		}
	}

	for (; i <= PRIME_LIMIT; i++){
		if (!mark[i]){
			primeList[idx++] = i;
		}
	}
}

bool isPrime(int prime)
{
	int index = 0;
	while (primeList[index] * primeList[index] <= prime && index < idx){
		if (prime % primeList[index] == 0){
			return false;
		}
		index++;
	}
	return prime >= 2;
}

int toInt(string str)
{
	int num = 0;
	for (int i = 0; i < str.length(); i++){
		num = num * 10 + (int)(str[i] - '0');
	}
	return num;
}

string toString(int num)
{
	string str = "";
	while (num != 0){
		str += ((num % 10) + '0');
		num /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

int solve(string str, int original)
{
	if (str.length() > 1){
		sort(str.begin(), str.end());
	}
	do{
		int num = toInt(str);
		int prime = abs(original - num);
		if (prime % 9 == 0){
			prime /= 9;
			if (prime < 1111111 && isPrime(prime)){
				return 1;
			}
		}
	} while (next_permutation(str.begin(), str.end()));
	return 0;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	seive();

#ifdef debug
	cout << idx << endl;
	for (int i = 0; i < idx; i++){
		cout << primeList[i] << " ";
	}
	cout << endl;
#endif

	int tc, p, q, counter;
	string str, temp;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++){
		scanf("%d %d", &p, &q);
		counter = 0;
		int temp;
		if (p>q) temp = p, p = q, q = temp;
		for (int j = p; j <= q; j++){
			str = toString(j);
			counter += solve(str, j);
		}
		//cout << "Case " << i << ": " << counter << endl;
		printf("Case %d: %d\n", i, counter);
	}


	return 0;
}