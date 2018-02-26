using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int n, space, Hash;

    scanf("%d", &n);
    space = n - 1;
    Hash = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < space; j++)
            printf(" ");

        for(int k = 1; k <= Hash; k++)
            printf("#");

        printf("\n");
        Hash++;
        space--;
    }



    return 0;
}
