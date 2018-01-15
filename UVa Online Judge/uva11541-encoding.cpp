#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, j, k, num;
    string line;
    char out;
    cin>>t;
    for(i = 1; i<= t; i++){
        cin>>line;
        cout<<"Case "<<i<<": ";
        for(int j = 0; line[j] != NULL; j++){
            num = 0;
            if(line[j] >= 'A' && line[j] <= 'Z'){
                out = line[j];
            }
            else{
                num = num*10 + (line[j++] - '0');
                while(line[j] >= '0' && line[j] <= '9'){
                    num = num*10 + (line[j++] - '0');
                }
                for(k = 1; k <= num; k++)
                    cout<<out;
                j--;
            }
        }
        cout<<endl;
    }

    return 0;
}
