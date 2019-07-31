#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
};
double cal(point x,point y)
{
    return (double)((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
const int maxnode=30020;
const int MaxN=55;
int N,M,K;
double eps=1e-8;
struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[MaxN],S[MaxN];
    int ands,ans[MaxN];
    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c)
    {
        for(int i = D[c];i != c;i = D[i])
            L[R[i]] = L[i], R[L[i]] = R[i];
    }
    void resume(int c)
    {
        for(int i = U[c];i != c;i = U[i])
            L[R[i]]=R[L[i]]=i;
    }
    bool v[maxnode];
    int f()
    {
        int ret = 0;
        for(int c = R[0];c != 0;c = R[c])v[c] = true;
        for(int c = R[0];c != 0;c = R[c])
            if(v[c])
            {
                ret++;
                v[c] = false;
                for(int i = D[c];i != c;i = D[i])
                    for(int j = R[i];j != i;j = R[j])
                        v[Col[j]] = false;
            }
        return ret;
 
    }
    bool Dance(int d)
    {
        if(d + f() > K) return false;
        if(R[0] == 0)return d <= K;
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c];i != c;i = D[i])
        {
            remove(i);
            for(int j = R[i];j != i;j = R[j])remove(j);
            if(Dance(d+1))return true;
            for(int j = L[i];j != i;j = L[j])resume(j);
            resume(i);
        }
        return false;
    }
} dlx;
point city[MaxN],rader[MaxN];
double mindis[60][60];
bool check(double r)
{
    dlx.init(M,N);
    double tmp=r*r;
    for(int i=1;i<=M;++i)
    {
        for(int j=1;j<=N;++j)
        {
            if(mindis[i][j]<=tmp)
            {
                dlx.Link(i,j);
            }
        }
    }
    return dlx.Dance(0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(int i=1;i<=N;++i)
        {
            scanf("%d%d",&city[i].x,&city[i].y);
        }
        for(int i=1;i<=M;++i)
        {
            scanf("%d%d",&rader[i].x,&rader[i].y);
        }
        for(int i=1;i<=M;++i)
        {
            for(int j=1;j<=N;++j)
            {
                mindis[i][j]=cal(rader[i],city[j]);
            }
        }
        double L=0,R=2000;
        while((R-L)>eps)
        {
            double mid=(R+L)/2;
            if(check(mid))
            {
                R=mid;
            }
            else
            {
                L=mid;
            }
        }
        printf("%.6lf\n",R);
    }
    return 0;
}