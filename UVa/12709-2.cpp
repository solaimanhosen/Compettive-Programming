#include <stdio.h>

int main()
{
    int t,i,j,k=0,count,vol[102];
    int l[102],w[102],h[102];
    int temp=0;
    while(scanf("%d",&t)==1)
    {

        if(t==0)
            break;

        i=0;temp=0;k=0;count=0;
        for(j=0;j<102;j++)
            vol[j]=0;
        while(t--)
        {
             scanf("%d%d%d",&l[i],&w[i],&h[i]);
             if(temp<h[i]){
                 temp=h[i];
             }
            i++;

        }
        count=i;
        for(j=0;j<count;j++)
        {
            if(temp==h[j]){
                vol[k]=l[j]*w[j]*h[j];
                k++;
            }
        }
        count=k;
        for(i=0;i<count-1;i++)
        {
            for(j=0;j<count-1;j++)
            {
                if(vol[j]<vol[j+1])
                {
                    temp=vol[j];
                    vol[j]=vol[j+1];
                    vol[j+1]=temp;
                }
            }
        }

        printf("%d\n",vol[0]);

    }
    return 0;
}
