#include <iostream>
#include <stdio.h>

using namespace std;


int set[100000009];
int visit[100000009];

int comp(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

int main()
{
	freopen("in.txt", "r", stdin);

	int t;
	int n, a, b, counter;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cin >> n >> a >> b;
		if (a < b)
			swap(a, b);
		n--;
		counter = 0;
		for (int i = 0; i <= n; i++){
			int ans = i*a + (n - i)*b;
			if (visit[ans] != tc){
				set[counter] = ans;
				counter++;
				visit[ans] = tc;
			}
			
		}
			
		qsort(set, counter, sizeof(int), comp);
		for (int i = 0; i < counter; i++)
		printf("%d ", set[i]);
		printf("\n");
	}



	return 0;
}