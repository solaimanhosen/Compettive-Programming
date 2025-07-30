#include <bits/stdc++.h>

using namespace std;

int main()
{
    int counter[101][101], m, n, i, j, Case = 1;
    char data[101][101];
    while(scanf("%d%d", &m, &n) == 2 && !(m == 0 && n == 0)){
        getchar();
        memset(counter, 0, sizeof(counter));
        for(i = 0; i<m; i++){
            scanf("%s", data[i]);
            //getchar();
            for(j = 0; j<n; j++){
                if(data[i][j] == '*'){
                    if(i>0){
                        counter[i-1][j]++;
                        if(j>0) counter[i-1][j-1]++;
                        if(j<n-1) counter[i-1][j+1]++;
                    }
                    if(j>0){
                        counter[i][j-1]++;
                    }
                    if(j<n-1) counter[i][j+1]++;
                    if(i<m-1){
                        counter[i+1][j-1]++;
                        counter[i+1][j]++;
                    }
                    if(i<m-1 && j<n-1) counter[i+1][j+1]++;
                }

            }

        }
        if(Case>1) printf("\n");
        printf("Field #%d:\n", Case++);
        for(i = 0; i<m; i++){
            for(j = 0; j<n; j++){
                if(data[i][j] == '*')
                    printf("%c", data[i][j]);
                else printf("%d", counter[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
