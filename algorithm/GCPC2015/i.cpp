#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int product[10020][102];
int ma[120];
int main()
{
    int W,S;
    scanf("%d%d",&W,&S);
    int X,Y;
    scanf("%d%d",&X,&Y);
    for(int i=0;i<W;i++)
    {
        for(int t=0;t<X;t++)
        {
            scanf("%d",&product[i][t]);
        }
    }
    for(int i=0;i<X;i++)
    {
        ma[i]=1e9;
    }
    for(int i=0;i<S;i++)
    {
       for(int t=0;t<X;t++)
       {
           int temp;
           scanf("%d",&temp);
           temp=Y-temp;
           ma[t]=min(ma[t],temp);
       }
    }
    for(int i=0;i<W;i++)
    {
        for(int t=0;t<X;t++)
        {
            if(product[i][t]>ma[t])
            {
                printf("%d",ma[t]);
            }
            else
            {
                printf("%d",product[i][t]);
            }
            if(t!=X-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}