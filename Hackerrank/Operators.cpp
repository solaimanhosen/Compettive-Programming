#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double m, tp, tx, total;
    scanf("%lf", &m);
    scanf("%lf", &tp);
    scanf("%lf", &tx);
    
    total = m + (m * tp / 100) + (m * tx / 100);
    
    printf("The total meal cost is %d dollars.", (int)(total + 0.5));
    
    
}