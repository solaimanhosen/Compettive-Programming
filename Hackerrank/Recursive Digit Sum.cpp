#include<iostream>
#include<cstdio>

using namespace std;

long long digitsum(long long num)
{
    long long sum = 0;
    while(num != 0){
        sum += num%10;
        num/=10;
    }
    return sum;
}

long long superdigit(long long num)
{
    if(num <= 9)
        return num;
    return superdigit(digitsum(num));
}


int main()
{
    long long num, k, n;
    string str;

    cin >> str >> k;
    n = 0;
    for(int i = 0; i <str.size(); i++){
        n += str[i] - '0';
    }
    cout << superdigit(n*k) << endl;



    return 0;
}






