#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator << (ostream& os, const vector<int>& list) {
    os << "{";
    for (int i = 0; i < list.size(); i++) {
        if (i != 0) os << ",";
        os << list[i];
    }
    os << "}";
    return os;
}

int main() {
    vector<int> list = vector<int>({1,1,2,3});
    int n = 24;

    while (n--) {
        cout << list << endl;
        next_permutation(list.begin(), list.end());
    }

    return 0;
}
