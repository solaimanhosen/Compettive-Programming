#include <stdio.h>

int prime[1050];

void primeGen()
{
    int i,j;
    for(i = 2; i<= 32; i++)
        for(j = i+i; j < 1050; j+=i)
            prime[j] = 1;
}

int main()
{
    primeGen();
    int value[128], i, j, num;
    char word[200];

    for(i = 'a', j =1; i <= 'z' ; i++, j++)
        value[i] = j;
    for(i = 'A', j =27; i <= 'Z' ; i++, j++)
        value[i] = j;

    while(gets(word)){
        num = 0;
        for(i = 0; word[i] != NULL; i++){
            num += value[word[i]];
        }
        if(prime[num] == 0)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
