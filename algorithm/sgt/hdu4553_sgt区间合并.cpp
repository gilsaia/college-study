#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1<<19;
struct node
{
    int lsum,rsum,msum,setv;
};
node ds[MAXN],ns[MAXN];
void build(node p[],int rt,int l,int r)
{
    p[rt].setv=-1;
    p[rt].lsum=p[rt].rsum=p[rt].msum=(r-l+1);
    if(l==r)
    {
        return;
    }
    int m=(l+r)>>1;
    build(p,rt<<1,l,m);
    build(p,rt<<1|1,m+1,r);
}
void pushup(node p[],int rt,int len)
{
    p[rt].lsum=p[rt<<1].lsum;
    if(p[rt].lsum==(len-(len>>1)))
    {
        p[rt].lsum+=p[rt<<1|1].lsum;
    }
    p[rt].rsum=p[rt<<1|1].rsum;
    if(p[rt].rsum==(len>>1))
    {
        p[rt].rsum+=p[rt<<1].rsum;
    }
    p[rt].msum=max(p[rt<<1].msum,max(p[rt<<1|1].msum,p[rt<<1].rsum+p[rt<<1|1].lsum));
}
void pushdown(node p[],int rt,int len)
{
    if(p[rt].setv!=-1)
    {
        p[rt<<1].setv=p[rt<<1|1].setv=p[rt].setv;
        p[rt<<1].lsum=p[rt<<1].rsum=p[rt<<1].msum=p[rt].setv?0:(len-(len>>1));
        p[rt<<1|1].lsum=p[rt<<1|1].rsum=p[rt<<1|1].msum=p[rt].setv?0:(len>>1);
        p[rt].setv=-1;
    }
}
int query(node p[],int rt,int l,int r,int v)
{
    if(v>p[rt].msum)
    {
        return 0;
    }
    if(l==r)
    {
        return l;
    }
    pushdown(p,rt,r-l+1);
    int m=(l+r)>>1;
    if(p[rt<<1].msum>=v)
    {
        return query(p,rt<<1,l,m,v);
    }
    if((p[rt<<1].rsum+p[rt<<1|1].lsum)>=v)
    {
        return m-p[rt<<1].rsum+1;
    }
    return query(p,rt<<1|1,m+1,r,v);
}
void update(node p[],int rt,int l,int r,int ql,int qr,int v)
{
    if(ql<=l&&qr>=r)
    {
        p[rt].setv=v;
        p[rt].lsum=p[rt].rsum=p[rt].msum=v?0:(r-l+1);
        return;
    }
    if(qr<l||ql>r)
    {
        return;
    }
    pushdown(p,rt,r-l+1);
    int m=(l+r)>>1;
    update(p,rt<<1,l,m,ql,qr,v);
    update(p,rt<<1|1,m+1,r,ql,qr,v);
    pushup(p,rt,r-l+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        printf("Case %d:\n",t);
        int n,m;
        scanf("%d%d",&n,&m);
        build(ds,1,1,n);
        build(ns,1,1,n);
        for(int i=0;i<m;++i)
        {
            char op[20];
            scanf("%s",op);
            if(op[0]=='D')
            {
                int v;
                scanf("%d",&v);
                int b=query(ds,1,1,n,v);
                if(b)
                {
                    printf("%d,let's fly\n",b);
                    update(ds,1,1,n,b,b+v-1,1);
                }
                else
                {
                    printf("fly with yourself\n");
                }
            }
            else if(op[0]=='N')
            {
                int v;
                scanf("%d",&v);
                int b=query(ds,1,1,n,v);
                if(b)
                {
                    printf("%d,don't put my gezi\n",b);
                    update(ds,1,1,n,b,b+v-1,1);
                    update(ns,1,1,n,b,b+v-1,1);
                }
                else
                {
                    int c=query(ns,1,1,n,v);
                    if(c)
                    {
                        printf("%d,don't put my gezi\n",c);
                        update(ds,1,1,n,c,c+v-1,1);
                        update(ns,1,1,n,c,c+v-1,1);
                    }
                    else
                    {
                        printf("wait for me\n");
                    }
                }
            }
            else if(op[0]=='S')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                update(ds,1,1,n,a,b,0);
                update(ns,1,1,n,a,b,0);
                printf("I am the hope of chinese chengxuyuan!!\n");
            }
        }
    }
    return 0;
}