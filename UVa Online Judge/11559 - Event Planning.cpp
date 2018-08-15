#include <iostream>

using namespace std;

int min(int a, int b)
{
	if (a <= b)
		return a;
	return b;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, b, h, w, price, freebed;
	while (cin >> n >> b >> h >> w){
		bool result = false;
		int min_cost = 30000000;
		for (int i = 0; i < h; i++){
			cin >> price;
			int max_freebed = -1;
			for (int j = 0; j < w; j++){
				cin >> freebed;
				if (freebed > max_freebed)
					max_freebed = freebed;
			}
			//cout << max_freebed << " " << n*price << endl;
			if (max_freebed >= n && b >= n*price){
				min_cost = min(min_cost, n*price);
				//cout << min_cost << endl;
				result = true;
			}
		}
		if (result)
			cout << min_cost << endl;
		else
			cout << "stay home" << endl;
	}
	


	return 0;
}