#include <iostream>

using namespace std;

int main()
{
    int num, age, counter[105], i, j, space;

    while(cin>>num && num!= 0){
        for( i = 0; i <= 100; i++)
            counter[i] = 0;
        space = 0;
        for( i = 0; i< num; i++){
            cin>>age;
            counter[age]++;
        }
        for ( i = 1; i <= 100; i++){
            if(counter[i] >=1){
                for( j = 1; j <= counter[i]; j++){
                    if( space == 1){
                        cout<<" ";
                        space = 0;
                    }
                    cout<<i;
                    if( j < counter[i])
                        cout<<" ";
                }
            }
            space = 1;
        }
        cout<<endl;
    }
    return 0;
}
