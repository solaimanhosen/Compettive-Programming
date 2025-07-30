#include <stdio.h>
#include <string.h>

int main()
{
    char str[2050];
    int i=1;
    while(gets(str)!=0)
    {
        if(str[0]=='#')
            break;
        else
        {
            if(strstr(str,"HELLO")!=0)
                printf("Case %d: %s\n",i++,"ENGLISH");
            else if(strstr(str,"HOLA")!=0)
                printf("Case %d: %s\n",i++,"SPANISH");
            else if(strstr(str,"HALLO")!=0)
                printf("Case %d: %s\n",i++,"GERMAN");
            else if(strstr(str,"BONJOUR")!=0)
                printf("Case %d: %s\n",i++,"FRENCH");
            else if(strstr(str,"CIAO")!=0)
                printf("Case %d: %s\n",i++,"ITALIAN");
            else if(strstr(str,"ZDRAVSTVUJTE")!=0)
                printf("Case %d: %s\n",i++,"RUSSIAN");
            else
                printf("Case %d: %s\n",i++,"UNKNOWN");
        }
    }
    return 0;
}
