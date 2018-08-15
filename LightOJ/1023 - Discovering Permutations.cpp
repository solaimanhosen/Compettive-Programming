#include <iostream>
#include <stdio.h>

using namespace std;

char str[26];

void swap(char* a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

char* substring(char* str, int s, int e)
{
	char* temp;
	for (int i = s; i < s + e; i++){
		temp += str[i];
	}
	return temp;
}



void init(int used[26])
{
	for (int i = 0; i < 26; i++)
		used[i] = 0;
}

void permute(int taken, int n, int &k, int used[]){
	if (k == 0)
		return;
	if (taken == n){
		for (int i = 0; i < n; i++)
			printf("%c", str[i]);
		printf("\n");
		k--;
		return;
	}
	for (int i = 0; i < n; i++){
		if (!used[i]){
			used[i] = 1;
			str[taken] = (char)('A' + i);
			permute(taken + 1, n, k, used);
			used[i] = 0;
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t, n, k, used[26];
	scanf("%d", &t);

	for (int i = 1; i <= t; i++){
		scanf("%d %d", &n, &k);
		init(used);
		printf("Case %d:\n", i);
		permute(0, n, k, used);
	}

	return 0;
}