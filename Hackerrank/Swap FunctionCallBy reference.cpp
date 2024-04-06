#include<stdio.h>
void sp(int* a,int* b,int* c)
{
    int temp,damp;
    temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;

}
int main()
{
    int x = 10;
    int y = 20;
    int z = 30;
    sp(&x,&y,&z);
    printf("x = %d,y =  %d,z = %d\n",x,y,z);
    return 0;
}
