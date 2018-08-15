#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX			1005
#define ll			long long

int main()
{
	int stick[MAX];
	int n, min = MAX, num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &num);
		stick[i] = num;
		if (num < min)
			min = num;
	}
	int cut = min;
	int counter = n;
	while (cut){
		min = MAX;
		printf("%d\n", counter);
		counter = 0;
		for (int i = 0; i < n; i++){
			if (stick[i] - cut > 0){
				counter++;
				stick[i] = stick[i] - cut;
				if (min > stick[i])
					min = stick[i];
			}
			else{
				stick[i] = 0;
			}
		}
		
		if (min == MAX)
			cut = 0;
		else
			cut = min;
	}


	return 0;
}