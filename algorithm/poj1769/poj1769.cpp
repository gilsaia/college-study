//dp的问题用线段树储存中间数据来减少时间
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1<<17;
const int MAX=1e9;
const int MAXM=500010;
int n,dat[2*MAXN-1],m,s[MAXM],t[MAXM],dp[MAXN];
void init(int n_)
{
    n=1;
    while(n<n_)
    {
        n*=2;
    }
    for(int i=0;i<2*n-1;++i)
    {
        dat[i]=MAX;
    }
}
void update(int k,int a)
{
    k+=n-1;
    dat[k]=a;
    while(k>0)
    {
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}
int query(int a,int b,int k,int l,int r)
{
    if(r<=a||b<=l)
    {
        return MAX;
    }
    if(a<=l&&r<=b)
    {
        return dat[k];
    }
    else
    {
        int vl=query(a,b,k*2+1,l,(l+r)/2);
        int vr=query(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&s[i],&t[i]);
    }
    int num=n;
    init(n);
    fill(dp,dp+num+1,MAX);
    dp[1]=0;
    update(1,0);
    for(int i=0;i<m;i++)
    {
        int v=min(dp[t[i]],query(s[i],t[i]+1,0,0,n)+1);
        dp[t[i]]=v;
        update(t[i],v);
    }
    printf("%d\n",dp[num]);
    return 0;
}