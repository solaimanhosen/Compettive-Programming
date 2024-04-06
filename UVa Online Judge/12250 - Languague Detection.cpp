
using namespace std;

#include <bits/stdc++.h>
#include <stdio.h>

int main()
{
	map<string, string> mm;
	string str;
	int caseNo = 1;

	mm["HELLO"] = "ENGLISH";
	mm["HOLA"] = "SPANISH";
	mm["HALLO"] = "GERMAN";
	mm["BONJOUR"] = "FRENCH";
	mm["CIAO"] = "ITALIAN";
	mm["ZDRAVSTVUJTE"] = "RUSSIAN";

	while (cin >> str)
	{
		if (str.compare("#") == 0){ /// if match to #
			break;
		}

		if (mm[str] == ""){  /// if there is no match
			cout << "Case " << caseNo << ": UNKNOWN" << endl;
			//printf("Case %d: UNKNOWN\n", caseNo);
		}
		else{
			cout << "Case " << caseNo << ": " << mm[str] << endl;
			//printf("Case %d: %s\n", caseNo, mm[str]);
		}
		caseNo++;
	}


	return 0;
}

