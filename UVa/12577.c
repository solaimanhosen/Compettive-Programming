
#include <stdio.h>
#include <string.h>

int main()
{
    char ch[10];
    int i=1;
    while(gets(ch)!=0)
    {
        if(ch[0]=='*')
            break;
        else{
            if(strcmp(ch,"Hajj")==0)
                printf("Case %d: %s%s",i++,ch,"-e-Akbar\n");
            else if(strcmp(ch,"Umrah")==0)
                printf("Case %d: %s",i++,"Hajj-e-Asghar\n");
        }
    }
    return 0;
}
