#include <cstdio>

using namespace std;

int main()
{
    int n, num, maxi, counter, _;

    maxi = counter = 0;
    _ = scanf("%d", &n);

    for(int i = 0; i < n; i++){
        _ = scanf("%d", &num);
        if(num == maxi)
            counter++;
        if(num > maxi){
            maxi = num;
            counter = 1;
        }
    }

    printf("%d\n", counter);



    return 0;
}
