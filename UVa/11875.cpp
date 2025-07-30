#include <iostream>

using namespace std;

int main()
{
    int t,i,j,count=0;
    int num;
    int aray[15];
    cin>>t;
    for(j=0; j<t; j++)
    {
        cin>>num;
        for(i=0; i<num; i++)
        {
            cin>>aray[i];
        }
        num=(num/2);
        cout<<"Case "<<j+1<<": "<<aray[num]<<endl;
    }

    return 0;
}
