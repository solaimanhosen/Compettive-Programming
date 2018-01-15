#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    char str[60], temp[15];

    while(gets(str))
    {
        int len, i=0, j=0;
        len=strlen(str);
        while(str[i]!=NULL)
        {
            if(str[i]==' ')
            {
                temp[j]=NULL;
                strrev(temp);
                cout<<temp<<" ";
                j=0;
            }
            else
            {
                temp[j]=str[i];
                j++;
            }
            i++;
        }
        temp[j]=NULL;
        strrev(temp);
        cout<<temp<<endl;
    }

    return 0;
}
