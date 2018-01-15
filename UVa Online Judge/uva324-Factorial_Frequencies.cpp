#include <bits/stdc++.h>
#define setValue(a) memset(a, 0, sizeof(a))

using namespace std;

vector<string> fact;

void factCal(int num)
{
    string temp = "", str;
    str = fact.back();
    int i, j, carry = 0, sum;
    for(i = 0; i<str.size(); i++){
        sum = carry + (str[i] - '0')*num;
        temp += (sum % 10) + '0';
        carry = sum / 10;
    }
    while(carry > 0){
        temp += (carry %10) + '0';
        carry /= 10;
    }
    cout<<temp<<endl;
    fact.push_back(temp);
}

int main()
{
    int i, num, counter[11], length;
    char temp[800];
    fact.push_back("1");
    for(i = 1; i <= 366; i++)
        factCal(i);
    while(cin>> num && !num == 0){
        length = fact[num].length();
        length = fact[num].copy(temp, length, 0);
        temp[length] = '\0';
        //cout<<temp<<endl;
        setValue(counter);
        for(i = 0; i < strlen(temp); i++){
            counter[temp[i] - '0']++;
        }
        printf("%d! --\n",num);

        printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",counter[0],counter[1],counter[2],counter[3],counter[4]);
        printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",counter[5],counter[6],counter[7],counter[8],counter[9]);


        /*printf("   (%d)%5d",0,counter[0]);
        printf("   (%d)%5d",1,counter[1]);
        printf("   (%d)%5d",2,counter[2]);
        printf("   (%d)%5d",3,counter[3]);
        printf("   (%d)%5d",4,counter[4]);
        printf("\n");
        printf("   (%d)%5d",5,counter[5]);
        printf("   (%d)%5d",6,counter[6]);
        printf("   (%d)%5d",7,counter[7]);
        printf("   (%d)%5d",8,counter[8]);
        printf("   (%d)%5d",9,counter[9]);
        printf("\n");*/
    }

    return 0;
}
