//线段树加dp的问题···然而线段树还是用不好唉·····
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9;
int tree[1<<20-1];
void build(int rt,int l,int r)
{
    tree[rt]=INF;
    if(l==r)
    {
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}
void update(int rt,int v,int k,int l,int r)
{
    if(l==r)
    {
        tree[rt]=min(tree[rt],v);
        return;
    }
    int m=(l+r)>>1;
    if(k<=m)
    {
        update(rt<<1,v,k,l,m);
    }
    else
    {
        update(rt<<1|1,v,k,m+1,r);
    }
    tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}
int query(int rt,int l,int r,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return tree[rt];
    }
    int m=(l+r)>>1;
    int temp=INF;
    if(L<=m)
    {
        temp=query(rt<<1,l,m,L,R);
    }
    if(R>m)
    {
        temp=min(temp,query(rt<<1|1,m+1,r,L,R));
    }
    return temp;
}
struct cow
{
    int l,r,c;
}cows[10020];
bool cmp(cow a,cow b)
{
    if(a.l==b.l)
    {
        return a.r<b.r;
    }
    return a.l<b.l;
}
int main()
{
    int N,M,E;
    scanf("%d%d%d",&N,&M,&E);
    for(int i=0;i<N;++i)
    {
        scanf("%d%d%d",&cows[i].l,&cows[i].r,&cows[i].c);
    }
    sort(cows,cows+N,cmp);
    build(1,M-1,E);
    int cur=M-1;
    update(1,0,cur,M-1,E);
    bool sign=1;
    for(int i=0;i<N;++i)
    {
        if(cows[i].l>cur+1)
        {
            sign=0;
            break;
        }
        int temp=query(1,M-1,E,cows[i].l-1,cows[i].r);
        update(1,temp+cows[i].c,cows[i].r,M-1,E);
        cur=max(cur,cows[i].r);
    }
    if(sign)
    {
        printf("%d\n",query(1,M-1,E,E,E));
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}