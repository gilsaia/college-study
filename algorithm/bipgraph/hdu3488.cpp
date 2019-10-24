
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1e9
using namespace std;
const int maxn=200+5;
 
struct Max_Match
{
    int n, W[maxn][maxn];
    int Lx[maxn],Ly[maxn];
    bool S[maxn],T[maxn];
    int left[maxn];
 
    bool match(int i)
    {
        S[i]=true;
        for(int j=1;j<=n;j++)if(Lx[i]+Ly[j]==W[i][j] && !T[j])
        {
            T[j]=true;
            if(left[j]==-1 || match(left[j]))
            {
                left[j]=i;
                return true;
            }
        }
        return false;
    }
 
    void update()
    {
        int a=1<<30;
        for(int i=1;i<=n;i++)if(S[i])
        for(int j=1;j<=n;j++)if(!T[j])
            a=min(a, Lx[i]+Ly[j]-W[i][j]);
        for(int i=1;i<=n;i++)
        {
            if(S[i]) Lx[i]-=a;
            if(T[i]) Ly[i]+=a;
        }
    }
 
    int solve(int n)
    {
        this->n=n;
        memset(left,-1,sizeof(left));
        for(int i=1;i<=n;i++)
        {
            Lx[i]=Ly[i]=0;
            for(int j=1;j<=n;j++)
                Lx[i]=max(Lx[i], W[i][j]);
        }
 
        for(int i=1;i<=n;i++)
        {
            while(true)
            {
                for(int j=1;j<=n;j++) S[j]=T[j]=false;
                if(match(i)) break;
                else update();
            }
        }
 
        int ans=0;
        for(int i=1;i<=n;i++)
            ans += W[left[i]][i];
        return -ans;
    }
}KM;
 
int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            KM.W[i][j]=-INF;
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            KM.W[u][v]= max(KM.W[u][v], -w);
        }
        printf("%d\n",KM.solve(n));
    }
    return 0;
}