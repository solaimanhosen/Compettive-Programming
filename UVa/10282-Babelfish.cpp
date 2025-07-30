#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <sstream>

using namespace std;

void parseText(string line, string& key, string& value)
{
    stringstream ss(line);
    ss >> value;
    ss >> key;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, string>mm;
    string key, value, line;
    while(getline(cin, line)){
        if(line.length() == 0) break;
        parseText(line, key, value);
        mm[key] = value;
    }
    while(getline(cin, key)){
        if(key.length() == 0) break;
        if(mm[key] == "") {
            cout << "eh" << endl;
        } else {
            cout << mm[key] << endl;
        }
    }

    return 0;
}