#include<stdio.h>
#include<iostream>
using namespace std;
struct Rajon
{
    Rajon()
    {
    }
    int x;
};

int main()
{
    Rajon* r = new Rajon();
    r->x = 10;
    std::cout<<"x= "<<r->x <<std::endl;
    return 0;

}
