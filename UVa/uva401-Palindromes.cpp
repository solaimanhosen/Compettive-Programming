#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[25];
    int len, i, sign1 = 0, sign2 = 0;
    while(cin>>str){
        sign1 = 1;
        sign2 = 1;
        len = strlen(str);
        for( i = 0; i< len/2; i++ ){
            if(str[i] != str[len - (i+1)]){
                sign1 = 0;
                break;
            }
        }
        if(sign1 == 1){

        }

    }
    return 0;
}
