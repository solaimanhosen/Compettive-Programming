#include <iostream>
#include <string>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int testCase;
	string s;
	cin >> testCase;
	while (testCase--){
		cin >> s;
		int strLen = s.size();

		if (s.compare("1") == 0 || s.compare("4") == 0 || s.compare("78") == 0){
			printf("+\n");
		}
		else if (s.compare(strLen-2,1,"3") == 0 && s.compare(strLen-1,1,"5") == 0){
			printf("-\n");
		}
		else if (s[0] == '9' && s[strLen - 1] == '4'){
			printf("*\n");
		}
		else if (s[0] == '1' && s[1] == '9' && s[2] == '0'){
			printf("?\n");
		}
		else{
			printf("+\n");
		}
	}

	return 0;

}
