#include <bits/stdc++.h>

using namespace std;

int divPossible(string num, int div)
{
    int i, len = num.length(), rem = 0, n;
    for(i = 0; i < len; i++){
        n = rem*10 + num[i] - '0';
        rem = n%div;
    }
    if(!rem)
        return 1;
    else
        return 0;
}

int main()
{
    int div4, div15, div55, div100, div400, counter = 0, leap, hulu, bulu ;
    string num;
    while(cin>>num){
        if(counter >= 1)
            cout<<endl;
        counter++;

        div4 = divPossible(num,4);
        div15 = divPossible(num,15);
        div55 = divPossible(num,55);
        div100 = divPossible(num,100);
        div400 = divPossible(num,400);

        leap = 0; hulu = 0; bulu = 0;
        if(div4){
            if(div100){
                if(div400)leap = 1;
            }
            else leap = 1;
        }
        if(div15)
            hulu = 1;
        if(leap==1){
            if(div55) bulu = 1;
        }
        if(leap == 1)
            cout<<"This is leap year."<<endl;
        if(hulu == 1)
            cout<<"This is huluculu festival year."<<endl;
        if(bulu == 1)
            cout<<"This is bulukulu festival year."<<endl;
        if(leap == 0 && hulu == 0 && bulu == 0)
            cout<<"This is an ordinary year."<<endl;
    }
    return 0;
}
