#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;

long long a[MAXN];
int n,q;

struct NODE
{

    int l,r,mid;
    long long nmin,nmax;
}tree[MAXN<<2];

void pushUp(int i)
{
    int lt=i<<1,rt=i<<1|1;
    tree[i].nmin=min(tree[lt].nmin,tree[rt].nmin);
    tree[i].nmax=max(tree[lt].nmax,tree[rt].nmax);
}

void build(int l,int r,int i)
{
    tree[i].l=l;
    tree[i].r=r;
    int mid=(l+r)>>1;
    tree[i].mid=mid;
    if(l>=r)
    {
        tree[i].nmax=tree[i].nmin=a[l];
        return ;
    }
    build(l,mid,i<<1);
    build(mid+1,r,i<<1|1);
    pushUp(i);
}

long long queryMax(int l,int r,int i)
{
    if(l<=tree[i].l&&tree[i].r<=r)
        return tree[i].nmax;
    long long res=-1e18;
    if(l<=tree[i].mid)res=max(res,queryMax(l,r,i<<1));
    if(r>tree[i].mid)res=max(res,queryMax(l,r,i<<1|1));
    return res;
}

long long queryMin(int l,int r,int i)
{
    if(l<=tree[i].l&&tree[i].r<=r)
        return tree[i].nmin;
    long long res=1e18;
    if(l<=tree[i].mid)res=min(res,queryMin(l,r,i<<1));
    if(r>tree[i].mid)res=min(res,queryMin(l,r,i<<1|1));
    return res;
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ah=a>>3,al=a%8,bh=b>>3,bl=b%8;
        int c=ah*bl,d=al*bh;
        int l=min(c,d)*min(a,b),r=max(c,d)*max(a,b);
        if(l<1)l=1;
        if(l>n)l=1;
        if(r>n)r=n;
        if(r<1)r=n;
        printf("%lld %lld\n",queryMax(l,r,1),queryMin(l,r,1));
    }
    return 0;
}