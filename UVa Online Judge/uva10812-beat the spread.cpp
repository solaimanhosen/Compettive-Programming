#include <iostream>

using namespace std;

int main()
{
    long long Test, TotalScore, AbsDiff, FirstScore, LastScore;
    cin>>Test;
    while(Test--){
        cin>>TotalScore>>AbsDiff;
        if((TotalScore + AbsDiff)%2==1 || TotalScore<AbsDiff)
            cout<<"impossible"<<endl;
        else{
            FirstScore = (TotalScore + AbsDiff)/2;
            LastScore = TotalScore - FirstScore;
            cout<<FirstScore<<" "<<LastScore<<endl;
        }
    }
    return 0;
}
