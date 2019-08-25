#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=40200;
int par[MAXN],valx[MAXN],valy[MAXN];
void init(int n)
{
    for(int i=0;i<=n;++i)
    {
        par[i]=i;
    }
}
int find(int x)
{
    if(x==par[x])
    {
        return x;
    }
    int tmp=par[x];
    par[x]=find(par[x]);
    valx[x]+=valx[tmp];
    valy[x]+=valy[tmp];
    return par[x];
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y,int op,int len)
{
    int tx=find(x);
    int ty=find(y);
    if(tx==ty)
    {
        return;
    }
    par[tx]=ty;
    valx[tx]=valx[y]-valx[x];
    valy[tx]=valy[y]-valy[x];
    if(op==0)//x->y 右
    {
        valy[tx]+=len;
    }
    else if(op==1)//x->y 下
    {
        valx[tx]+=len;
    }
    else if(op==2)//x->y 左
    {
        valy[tx]-=len;
    }
    else if(op==3)//x->y 上
    {
        valx[tx]-=len;
    }
}
int pat[40020][4];
int qur[10020][3];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=0;i<m;++i)
    {
        char tmp[10];
        scanf("%d %d %d %s",&pat[i][0],&pat[i][1],&pat[i][2],tmp);
        if(tmp[0]=='E')
        {
            pat[i][3]=0;
        }
        else if(tmp[0]=='S')
        {
            pat[i][3]=1;
        }
        else if(tmp[0]=='W')
        {
            pat[i][3]=2;
        }
        else if(tmp[0]=='N')
        {
            pat[i][3]=3;
        }
    }
    int k;
    scanf("%d",&k);
    int nowstep=0;
    for(int i=0;i<k;++i)
    {
        scanf("%d%d%d",&qur[i][0],&qur[i][1],&qur[i][2]);
        for(int j=nowstep;j<qur[i][2];++j)
        {
            unite(pat[j][0],pat[j][1],pat[j][3],pat[j][2]);
        }
        nowstep=qur[i][2];
        if(same(qur[i][0],qur[i][1]))
        {
            int dis=abs(valx[qur[i][0]]-valx[qur[i][1]])+abs(valy[qur[i][0]]-valy[qur[i][1]]);
            printf("%d\n",dis);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}