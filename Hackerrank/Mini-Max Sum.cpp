#include <iostream>

using namespace std;

#define long long ll;


int main() {
    ll aray[10], max, min, num;
    num = 0;
    for(int i = 0; i < 5; i++)
    {
        cin >> aray[i];
        num += aray[i];
    }
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 5; j++){
            if(aray[i] > aray[j]){
                ll temp = aray[i];
                aray[i] = aray[j];
                aray[j] = temp;
            }
        }
    }

    //sort(aray+0,aray+5);
    min = num - aray[4];
    max = num - aray[0];

    cout << min << " " << max << endl;

    return 0;
}
