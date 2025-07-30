
#include <iostream>

using namespace std;

int main()
{
    int Test, num, data, maxNum, i = 1;
    cin>>Test;
    while(Test--){
        cin>>num;
        maxNum = 0;
        while(num--){
            cin>>data;
            if(data>maxNum)
                maxNum = data;
        }
        cout<<"Case "<<i++<<": "<<maxNum<<endl;
    }
    return 0;
}
