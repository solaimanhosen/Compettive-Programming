#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int LIMIT = 1e6 + 1;

pair<vector<bool>, vector<int>> preprocess(int n) {
	vector<bool> isPrime = vector<bool>(n, true);
	isPrime[0] = isPrime[1] = false;
	
	int sqrt_n = static_cast<int>(sqrt(n));
	for (int i = 2; i <= sqrt_n; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j < n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	vector<int> primes = vector<int>();
	for (int i = 2; i < n; ++i) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}

	return make_pair(isPrime, primes);

}

int main() {
	auto [isPrime, primes] = preprocess(LIMIT);

	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}

		cout << n << ":" << endl;
		bool isFound = false;
		for (int prime : primes) {
			if (prime > n / 2) {
				break;
			}
			if (isPrime[n - prime]) {
				isFound = true;
				cout << prime << "+" << n - prime << endl;
				break;
			}
		}

		if (!isFound) {
			cout << "NO WAY!" << endl;
		}
	}

	return 0;
}
