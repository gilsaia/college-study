#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct trac
{   
    ll x,y,height,width;
};
trac trang[3040];
bool cmp(trac a,trac b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}
ll count(ll x,ll y)
{
    ll ans=0;
    while(x!=0&&y!=0)
    {
        ans+=x*y;
        --x,--y;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=0;i<n;++i)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1<x2)
        {
            swap(x1,x2);
        }
        if(y1<y2)
        {
            swap(y1,y2);
        }
        trang[i].x=x2,trang[i].y=y2,trang[i].width=x1-x2,trang[i].height=y1-y2;
        sum+=count(x1-x2,y1-y2);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            if(j==i)
            {
                continue;
            }
            trac cmp1=trang[i],cmp2=trang[j];
            if((cmp1.x==cmp2.x+cmp2.width)||(cmp2.x==cmp1.x+cmp1.width))
            {
                if(cmp1.y+cmp1.height>cmp2.y+2)
                {
                    ll tmp=min(cmp1.y+cmp1.height-cmp2.y,cmp2.height)-2;
                    sum=sum+count(cmp1.width+cmp2.width,tmp)-count(cmp1.width,tmp)-count(cmp2.width,tmp);
                }
                else if(cmp2.y+cmp2.height>cmp1.y+2)
                {
                    ll tmp=min(cmp2.y+cmp2.height-cmp1.y,cmp1.height)-2;
                    sum=sum+count(cmp1.width+cmp2.width,tmp)-count(cmp1.width,tmp)-count(cmp2.width,tmp);
                }
            }
            else if((cmp1.y==cmp2.y+cmp2.height)||(cmp2.y==cmp1.y+cmp1.height))
            {
                if(cmp1.x+cmp1.width>cmp2.x+2)
                {
                    ll tmp=min(cmp1.x+cmp1.width-cmp2.x,cmp2.width)-2;
                    sum=sum+count(tmp,cmp1.height+cmp2.height)-count(tmp,cmp1.height)-count(tmp,cmp2.height);
                }
                else if(cmp2.x+cmp2.width>cmp1.x+2)
                {
                    ll tmp=min(cmp2.x+cmp2.width-cmp1.x,cmp1.width)-2;
                    sum=sum+count(tmp,cmp1.height+cmp2.height)-count(tmp,cmp1.height)-count(tmp,cmp2.height);
                }
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}