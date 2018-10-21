//可以理解成最小费用流找最小费用···但题目要求的不用找到最佳答案只要验证所给是否最佳即可···验证残余网络中是否含有负圈即可··
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=120,MAXM=120,MAXV=260;
const int INF=1e9;
int N,M;
int X[120],Y[120],B[120];
int P[120],Q[120],C[120];
int E[120][120];
int g[260][260];
int preve[260][260];
bool used[260];
void solve()
{
    int V=N+M+1;
    for(int i=0;i<V;++i)
    {
        fill(g[i],g[i]+V,INF);
    }
    for(int j=0;j<M;++j)
    {
        int sum=0;
        for(int i=0;i<N;++i)
        {
            int c=abs(X[i]-P[j])+abs(Y[i]-Q[j])+1;
            g[i][N+j]=c;
            if(E[i][j]>0)
            {
                g[N+j][i]=-c;
            }
            sum+=E[i][j];
        }
        if(sum>0)
        {
            g[N+M][N+j]=0;
        }
        if(sum<C[j])
        {
            g[N+j][N+M]=0;
        }
    }
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<V;++j)
        {
            preve[i][j]=i;
        }
    }
    for(int k=0;k<V;++k)
    {
        for(int i=0;i<V;++i)
        {
            for(int j=0;j<V;++j)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                {
                    g[i][j]=g[i][k]+g[k][j];
                    preve[i][j]=preve[k][j];
                    if(i==j&&g[i][i]<0)
                    {
                        fill(used,used+V,false);
                        for(int v=i;!used[v];v=preve[i][v])
                        {
                            used[v]=true;
                            if(v!=N+M&&preve[i][v]!=N+M)
                            {
                                if(v>=N)
                                {
                                    E[preve[i][v]][v-N]++;
                                }
                                else
                                {
                                    E[v][preve[i][v]-N]--;
                                }
                            }
                        }
                        printf("SUBOPTIMAL\n");
                        for(int x=0;x<N;++x)
                        {
                            for(int y=0;y<M;++y)
                            {
                                printf("%d%c",E[x][y],y+1==M?'\n':' ');
                            }
                        }
                        return;
                    }
                }
            }
        }
    }
    printf("OPTIMAL\n");
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;++i)
    {
        scanf("%d%d%d",&X[i],&Y[i],&B[i]);
    }
    for(int i=0;i<M;++i)
    {
        scanf("%d%d%d",&P[i],&Q[i],&C[i]);
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            scanf("%d",&E[i][j]);
        }
    }
    solve();
    return 0;
}