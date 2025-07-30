#include <stdio.h>

int main()
{
    int numOfPress[128], t, i, j, counter;
    char str[105];
    numOfPress['a'] = 1;
    numOfPress['b'] = 2;
    numOfPress['c'] = 3;
    numOfPress['d'] = 1;
    numOfPress['e'] = 2;
    numOfPress['f'] = 3;
    numOfPress['g'] = 1;
    numOfPress['h'] = 2;
    numOfPress['i'] = 3;
    numOfPress['j'] = 1;
    numOfPress['k'] = 2;
    numOfPress['l'] = 3;
    numOfPress['m'] = 1;
    numOfPress['n'] = 2;
    numOfPress['o'] = 3;
    numOfPress['p'] = 1;
    numOfPress['q'] = 2;
    numOfPress['r'] = 3;
    numOfPress['s'] = 4;
    numOfPress['t'] = 1;
    numOfPress['u'] = 2;
    numOfPress['v'] = 3;
    numOfPress['w'] = 1;
    numOfPress['x'] = 2;
    numOfPress['y'] = 3;
    numOfPress['z'] = 4;
    numOfPress[' '] = 1;

    scanf("%d",&t);
    getchar();
    for(i = 1; i<= t; i++){
        //scanf("%[^\n]s",str);
        gets(str);
        printf("Case #%d: ",i);
        counter = 0;
        for(j = 0; str[j] != NULL; j++){
            counter += numOfPress[str[j]];
        }
        printf("%d\n",counter);
    }
    return 0;
}
