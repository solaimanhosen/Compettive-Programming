#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, pos, i, j, temp;
    char in[105][15];

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        getchar();
        pos = 0;
        for(i = 1; i <= n; i++){
            gets(in[i]);
            if(!strcmp(in[i], "LEFT")) pos--;
            else if(!strcmp(in[i], "RIGHT")) pos++;
            else{
                temp = 0;
                for(j = 8; in[i][j] != NULL; j++){
                    temp = temp*10 + in[i][j] - '0';
                }
                if(!strcmp(in[temp], "LEFT")){
                    pos--;
                    strcpy(in[i], "LEFT");
                    in[i][4] = '\0';
                }
                else{
                    pos++;
                    strcpy(in[i], "RIGHT");
                    in[i][5] = '\0';
                }
            }
        }
        printf("%d\n", pos);
    }

    return 0;
}
