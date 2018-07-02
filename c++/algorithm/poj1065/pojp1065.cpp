//这里的做法是先按长度递增的方法排序然后求出各种完全的递增子序列，求出其最多的个数
//但也可根据某些神奇的数学运算发现，按长度排完序后整体重量的最大下降子序列所包含的元素数就是最小上升子序列的的个数
#include<stdio.h>
#include<algorithm>
using namespace std;
struct wood
{
    int lon;
    int weight;
};
bool used[5020];
wood dat[5020];
bool comp(wood a,wood b)
{
    if(a.lon==b.lon)
    {
        return a.weight<b.weight;
    }
    else
    {
        return a.lon<b.lon;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&dat[i].lon,&dat[i].weight);
        }
        sort(dat,dat+n,comp);
        memset(used,1,sizeof(used));
        int count=0,last;
        for(int i=0;i<n;i++)
        {
            if(used[i])
            {
               used[i]=0;
               last=dat[i].weight;
               for(int j=i+1;j<n;j++)
               {
                   if(dat[j].weight>=last&&used[j])
                   {
                       used[j]=0;
                       last=dat[j].weight;
                   }
               } 
               count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}