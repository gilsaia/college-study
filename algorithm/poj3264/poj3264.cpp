//线段树的题···基本照模板走即可···一个存最大值一个存最小值···
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=1<<17;
const int INTMA=1e9;
int n,dat[2*MAX_N-1],tad[2*MAX_N-1];
void init(int n_)
{
    n=1;
    while(n<n_)
    {
        n<<=1;
    }
    for(int i=0;i<2*n-1;i++)
    {
        dat[i]=INTMA;
        tad[i]=0;
    }
}
void update(int k,int a)
{
    k+=n-1;
    dat[k]=a;
    tad[k]=a;
    while(k>0)
    {
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
        tad[k]=max(tad[k*2+1],tad[k*2+2]);
    }
}
int querymin(int a,int b,int k,int l,int r)
{
    if(r<=a||b<=l)
    {
        return INTMA;
    }
    if(a<=l&&r<=b)
    {
        return dat[k];
    }
    else
    {
        int vl=querymin(a,b,k*2+1,l,(l+r)/2);
        int vr=querymin(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}
int querymax(int a,int b,int k,int l,int r)
{
    if(r<=a||b<=l)
    {
        return 0;
    }
    if(a<=l&&r<=b)
    {
        return tad[k];
    }
    else
    {
        int vl=querymax(a,b,k*2+1,l,(l+r)/2);
        int vr=querymax(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
}
int main()
{
    int q,num;
    scanf("%d%d",&num,&q);
    n=num;
    init(n);
    for(int i=0;i<num;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        update(i,tmp);
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        --l;
        int ans=querymax(l,r,0,0,n)-querymin(l,r,0,0,n);
        printf("%d\n",ans);
    }
    return 0;
}