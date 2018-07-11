//也是基础的多源最短路问题，只要注意一下最后求均值用int并且除的N是不算自身的即可
#include<stdio.h>
#include<algorithm>
using namespace std;
int d[320][320];
const int INF=1e9;
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            d[i][j]=INF;
        }
        d[i][i]=0;
    }
    for(int i=0;i<M;i++)
    {
        int k,temp[320];
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&temp[j]);
        }
        for(int j=0;j<k;j++)
        {
            for(int m=j;m<k;m++)
            {
                if(j!=m)
                {
                    d[temp[j]][temp[m]]=1;
                    d[temp[m]][temp[j]]=1;
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    int ans=INF;
    for(int i=1;i<=N;i++)
    {
        int temp=0;
        for(int j=1;j<=N;j++)
        {
            temp+=d[i][j];
        }
        ans=min(ans,(temp*100)/(N-1));
    }
    printf("%d\n",ans);
    return 0;
}