
#include <stdio.h>
#include <iomanip>


int main()
{
    int t,i,j,cnt;
    int num;
    int mark[1050];
    int sum;
    float result;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        sum=0;
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            scanf("%d",&mark[j]);
            sum+=mark[j];
        }
        sum/=num;
        cnt=0;
        for(j=0;j<num;j++)
        {
            if(mark[j]>sum)
                cnt++;
        }
        result=(float)cnt/num*100;
        printf("%.3f%c\n",result,37);

    }
    return 0;
}

/*using namespace std;


/*int main()
{
    int i, j, count=0;
    long long int TestCase;
    cin>>TestCase;
    int Numbers[TestCase];
    double temp[1050];
    long double avg[TestCase];
    float result[TestCase];
    for(i=0;i<TestCase;i++){
        cin>>Numbers[i];
        avg[i]=0;
        result[i]=0;
        for(j=0;j<Numbers[i];j++){
            cin>>temp[j];
            avg[i]+=temp[j];
        }
        avg[i]=(avg[i]/Numbers[i]);
        cout<<avg[i]<<endl;
        for(j=0;j<Numbers[i];j++){
            if(avg[i]<temp[j])
            {
                count++;cout<<count<<endl;
            }

        }
        cout<<result[i]<<endl;
        result[i]=count/Numbers[i];
        result[i]*=100;
        cout<<result[i]<<endl;

    }
    for(i=0;i<TestCase;i++){
        cout<<result[i]<<endl;
    }

    return 0;
}*/
