#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num, Time, cost1,cost2, TestCase, i =1, dur1, dur2, cost;
    cin>>TestCase;
    while(TestCase--){
        cin>>num;
        cost1 = cost2 = 0;
        while(num--){
            cin>>Time;

            dur1 = 29;
            dur2 = 59;
            while(Time>dur1){
                dur1+=30;
                cost1++;
            }
            cost1++;
            while(Time>dur2){
                dur2+=60;
                cost2++;
            }
            cost2++;
        }
        cost1*=10;cost2*=15;

        if(cost1==cost2)cout<<"Case "<<i<<": Mile Juice "<<cost1<<endl;
        else if(cost1<cost2) printf("Case %d: Mile %d\n", i,cost1);
        else printf("Case %d: Juice %d\n", i,cost2);
        i++;
    }
    return 0;
}
