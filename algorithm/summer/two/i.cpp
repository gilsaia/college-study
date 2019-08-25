#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1e9;
int n,m,p;
int dp1[205][50020];
int dp2[205][50020];
struct dessert
{
    int energy,num,space;
};
struct trunk
{
    int space,num,cost;
};
dessert cargo[205];
trunk velci[205];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d",&cargo[i].energy,&cargo[i].space,&cargo[i].num);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&velci[i].space,&velci[i].cost,&velci[i].num);
        }
        memset(dp1,INF,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        for(int i=0;i<n;++i)
        {
            dp1[i][0]=0;
            for(int j=0;j<=p;++j)
            {
                if(dp1[i][j]==INF)
                {
                    continue;
                }
                for(int t=1;t<=cargo[i].num;++t)
                {
                    int tmp=j+t*cargo[i].energy;
                    dp1[i+1][tmp]=min(dp1[i+1][tmp],dp1[i][j]+t*cargo[i].space);
                }
            }
        }
        int minspace=INF;
        for(int i=p;i<=p+120;++i)
        {
            minspace=min(minspace,dp1[n][i]);
        }
        for(int i=0;i<m;++i)
        {
            dp2[i][0]=0;
            for(int j=0;j<=50000;++j)
            {
                if(dp2[i][j]==-1)
                {
                    continue;
                }
                for(int t=1;t<=velci[i].num;++t)
                {
                    int tmp=j+t*velci[i].cost;
                    dp2[i+1][tmp]=max(dp2[i+1][tmp],dp2[i][j]+t*velci[i].space);
                }
            }
        }
        if(minspace==INF)
        {
            printf("TAT\n");
        }
        else
        {
            int mincost=-1;
            for(int i=0;i<=50000;++i)
            {
                if(dp2[m][i]>=minspace)
                {
                    mincost=i;
                    break;
                }
            }
            if(mincost==-1)
            {
                printf("TAT\n");
            }
            else
            {
                printf("%d\n",mincost);
            }
        }
    }
    return 0;
}