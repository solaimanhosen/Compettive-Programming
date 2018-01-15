#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num, h[55], avg, counter, j=1;

    while(cin>>num && num != 0){
        int i;
        avg = 0;
        counter = 0;
        for( i= 0; i< num; i++ ){
            cin>>h[i];
            avg+= h[i];
        }
        avg/= i;
        for( i = 0; i< num; i++){
            if(avg<h[i])
                counter+= (h[i] - avg);
        }
        cout<<"Set #"<<j++<<endl;
        cout<<"The minimum number of moves is "<<counter<<"."<<endl<<endl;

    }
    return 0;
}
