//emmmmmmmm搬得题解···这个用了线段树···仔细看看之后好像不是很难懂···但是第一次做线段树的题吧···
#include <stdio.h>
 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
 
#define N 500010
 
int tree[N<<2];
 
const int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,
                       1260,1680,2520,5040,7560,10080,15120,20160,25200,
                       27720,45360,50400,55440,83160,110880,166320,221760,
                       277200,332640,498960,554400,665280
                      };
 
const int factorNum[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,
                       64,72,80,84,90,96,100,108,120,128,144,160,168,180,
                       192,200,216,224
                      };
 
struct child
{
    char name[15];
    int val;
}c[N];
 
void Build(int l,int r,int rt)
{
    tree[rt]=r-l+1;
    if(l==r)
        return;
    int m=(l+r)>>1;
    Build(lson);
    Build(rson);
}
 
int Update(int p,int l,int r,int rt)
{
    tree[rt]--;
    if(l==r)
         return r;
    int m=(l+r)>>1;
    if(p<=tree[rt<<1])
         return Update(p,lson);
    return Update(p-tree[rt<<1],rson);
}
 
int main()
{
    int i,n,k,&mod=tree[1];
    while(~scanf("%d%d",&n,&k))
    {
        for(i=1;i<=n;i++)
            scanf("%s%d",c[i].name,&c[i].val);
        Build(1,n,1);
        int cnt=0;
        while(cnt<35 && antiprime[cnt]<=n)
            cnt++;
        cnt--;
        int pos=0;
        c[pos].val=0;
        for(i=0;i<antiprime[cnt];i++)
        {
            if(c[pos].val>0)
                k=((k+c[pos].val-2)%mod+mod)%mod+1;
            else
                k=((k+c[pos].val-1)%mod+mod)%mod+1;
            pos=Update(k,1,n,1);
        }
        printf("%s %d\n",c[pos].name,factorNum[cnt]);
    }
    return 0;
 }