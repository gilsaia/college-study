//多源最短路加dp问题，日文原题没有英文翻译是真看不懂，看懂了也是真不会做找的题解，先按多源最短路把走陆路和走海路分别求好
//dp[i][j]代表走到要求的第i个城市时船停在j的情况来依次dp，按题意似乎第一个城市必定是船和人所在的1号城市，要注意考虑进只走陆路的情况
//还有因为有多个相加所以INF不要太大不然可能会超限
#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=1e5;
int land[210][210],sea[210][210];
int dp[1020][210],aim[1020];
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)
        {
            break;
        }
        for(int i=0;i<=N;i++)
        {
            for(int t=0;t<=N;t++)
            {
                land[i][t]=INF;
                sea[i][t]=INF;
            }
            land[i][i]=0;
            sea[i][i]=0;
        }
        for(int i=0;i<M;i++)
        {
            int u,v,c;
            char w;
            scanf("%d %d %d %c",&u,&v,&c,&w);
            if(w=='S')
            {
                sea[u][v]=min(sea[u][v],c);
                sea[v][u]=min(sea[v][u],c);
            }
            else
            {
                land[u][v]=min(land[u][v],c);
                land[v][u]=min(land[v][u],c);
            }
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&aim[i]);
        }
        for(int k=1;k<=N;k++)
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    land[i][j]=min(land[i][j],land[i][k]+land[k][j]);
                    sea[i][j]=min(sea[i][j],sea[i][k]+sea[k][j]);
                }
            }
        }
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=N;j++)
            {
                dp[i][j]=INF;
            }
        }
        dp[1][aim[1]]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=N;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]+land[aim[i-1]][aim[i]]);
                for(int k=1;k<=N;k++)
                {
                    dp[i][k]=min(dp[i][k],dp[i-1][j]+land[aim[i-1]][j]+sea[j][k]+land[k][aim[i]]);
                }
            }
        }
        int ans=INF;
        for(int i=1;i<=N;i++)
        {
            ans=min(dp[m][i],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}