#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
ll cir[100020];
ll val[100020];
ll res[100020];
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=0;i<n;++i)
    {
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        if(cir[x]!=0)
        {
            int tmp=x;
            x=y;
            y=tmp;
        }
        val[x]=z;
        cir[x]=y;
        sum+=z;
    }
    int next=cir[1],now=1;
    for(int i=0;i<n/2;++i)
    {
        sum-=val[now];
        sum-=val[now];
        int tmp=now;
        now=cir[next];
        next=cir[now];
    }
    res[now]=sum/2;
    for(int i=1;i<n;++i)
    {
        res[next]=val[now]-res[now];
        now=next;
        next=cir[now];
    }
    for(int i=1;i<=n;++i)
    {
        printf("%lld",res[i]);
        if(i!=n)
        {
            printf("\n");
        }
    }
    return 0;
}