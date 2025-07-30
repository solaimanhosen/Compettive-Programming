#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[5];
    int TestCase;
    cin>>TestCase;
    while(TestCase--)
    {
        cin>>str;
        if(strlen(str)==5)
            cout<<"3\n";
        else if(str[1]=='n' || str[2]=='e')
            cout<<"1\n";
        else
            cout<<"2\n";
    }

    return 0;
}
