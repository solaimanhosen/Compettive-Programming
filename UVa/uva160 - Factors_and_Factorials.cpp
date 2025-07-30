#include <bits/stdc++.h>

using namespace std;

vector <int> pf[101];
int counter[101][101], mark[101], prime[101], total = 0;

void primeGen()
{
    int i,j;
    memset(mark, 0, 100);
    for(i = 4; i <= 100; i += 2)
        mark[i] = 1;
    for(i = 3; i<= 10; i+=2)
        for(j = i + i; j <= 100; j += i)
            mark[j] = 1;
    for(i = 2, j= 0; i<= 100; i++)
        if(mark[i] == 0)
            prime[j++] = i;
    total = j;
}

void primeFactorize(int num)
{
    if(!mark[num])
        pf[num].push_back(num);
    else
    {
        int i = 0, temp = num;
        while(prime[i] * prime[i] <= temp)
        {
            while(temp % prime[i] == 0)
            {
                pf[num].push_back(prime[i]);
                temp = temp/prime[i];
            }
            i++;
        }
        if(temp > 1)
            pf[num].push_back(temp);
    }
}

void setValue()
{
    int i, j;
    for(i = 0; i<=100; i++)
        for(j = 0; j <= 100; j++)
            counter[i][j] = 0;
}
int main()
{
    setValue();
    primeGen();
    int i, j, num;
    for(i = 2; i <= 100; i++)
    {
        primeFactorize(i);
        for(j = 0; j < pf[i].size(); j++)
            counter[i][pf[i][j]]++;
    }
    for(i = 2; i <= 100; i++)
        for(j = 0; j <= 100; j++)
            counter[i][j] += counter[i-1][j];

    while(scanf("%d", &num) == 1 && num != 0)
    {
        printf("%3d! =", num);
        int cnt = 0;
        for(i = 0; i<= num; i++)

            if(counter[num][i]>0)
            {
                if(cnt >= 15){
                    printf("\n%9d", counter[num][i]);
                    cnt = 1;
                }
                else
                    printf("%3d", counter[num][i]);
                cnt++;
            }
        puts("");
    }

    return 0;
}
