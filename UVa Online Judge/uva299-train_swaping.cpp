#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TestCase, Length, Num[55], SwapCounter, Temp;
    cin>>TestCase;
    while(TestCase--){
        cin>>Length;
        for(int i = 0; i< Length; i++)
            cin>>Num[i];
        SwapCounter = 0;
        for(int i = 0; i< Length - 1; i++){
            for(int j = i + 1; j< Length; j++){
                if(Num[i]>Num[j])
                {
                    Temp = Num[i];
                    Num[i] = Num[j];
                    Num[j] = Temp;
                    SwapCounter++;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<SwapCounter<<" swaps."<<endl;
    }
    return 0;
}
