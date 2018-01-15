
#include <iostream>

using namespace std;

int main()
{
    int num, counter, TestCase = 1;
    while(cin>>num && num>0){
        counter = 0;
        for(int i = 1; i < num; i = 2*i){
            counter++;
        }
        cout<<"Case "<<TestCase++<<": "<<counter<<endl;
    }
    return 0;
}
