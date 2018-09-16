//最后也是找了题解···emmmmmmmm线段树的题···有点难···
#include <stdio.h>
#include <string.h>
const int Max=100005;
int n,q;
int num[Max],sum[Max],node[Max<<2];
int max(int a,int b)
{
    if(a<b)a=b;
    return a;
}
void PushUp(int tr)
{
    node[tr]=max(node[tr<<1],node[tr<<1|1]);
}
void Build(int l,int r,int tr)
{
    if(l==r)
    {
        node[tr]=num[l];
        return ;
    }
    int m=(l+r)>>1;
    Build(l,m,tr<<1);
    Build(m+1,r,tr<<1|1);
    PushUp(tr);
}
int  Findnum(int key ,int l,int r)
{
    int m;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(sum[m]>key)
        {
            r=m-1;
        }
        else if(sum[m]<key)
        {
            l=m+1;
        }
        else break;
    }
    if(sum[m-1]>=key)
    {
        return m-1;
    }
    else if(sum[m]>=key)
    {
        return m;
    }
    else
    {
        return m+1;
    }
}
int query(int L,int R ,int l , int r , int tr )
{
    if(L<=l&&r<=R)
    {
        return node[tr];
    }
    int m=(l+r)>>1;
    int ans=0;
    if(L<=m)ans=query(L,R,l,m,tr<<1);
    if(m<R)ans=max(ans,query(L,R,m+1,r,tr<<1|1));
    return ans;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        memset(num,0,sizeof(num));
        memset(node,0,sizeof(node));
        memset(sum,0,sizeof(sum));
        scanf("%d",&q);
        int tag,chack,cnt=1,a,b;
        scanf("%d",&chack);
        num[cnt]=1;
        sum[0]=0;
        for(int i=1;i<n;i++) //记录一共有几个不同的数字  cnt计数
        {
            scanf("%d",&tag); 
            if(chack==tag)
            {
                num[cnt]++;   //num数组记录每个数字出现了几次
            }
            else
            {
                sum[cnt]=sum[cnt-1]+num[cnt];  //sum数组记录从第一种数开始到第i种数一共有多少个
                chack=tag;
                cnt++;
                num[cnt]=1;
            }
        }
        sum[cnt]=sum[cnt-1]+num[cnt];
        Build(1,cnt,1); //对于数的出现次数计数
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&a,&b);
            int x=Findnum(a,1,cnt);  //二分查找出第a个数是第几种数
            int y=Findnum(b,1,cnt);
            int ans=sum[x]-a+1;      //计算出在a到b这个区间中第x种数有几个
            if(x==y)                 //当x与y相等时，代表着区间a到b内只有一种数
            {
                printf("%d\n",b-a+1);
                continue;
            }
            if(x+1<=y-1)
            {
                ans=max(ans,query(x+1,y-1,1,cnt,1));
            }
            ans=max(ans,num[y]-sum[y]+b);
            printf("%d\n",ans);
        }
    }
    return 0;
}