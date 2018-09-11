//emmmmmmmm感觉能看懂但是很难想的一道题···首先因为规模太大需要坐标离散化···然后就逐渐扫描来确定哪段是中间···计算和的时候为了快速计算就用了树状数组
#include<cstdio>
#include<algorithm>
using namespace std;
int n,has[200010],sum[200010];
struct point
{
    int x,y;
}dat[200010];
int zm[200010];
void add(int i,int x)
{
    while(i<=n)
    {
        sum[i]+=x;
        i+=i&-i;
    }
}
int query(int l,int r)
{
    int right=0,left=0;
    l--;
    while(l>0)
    {
        left+=sum[l];
        l-=l&-l;
    }
    while(r>0)
    {
        right+=sum[r];
        r-=r&-r;
    }
    return (right-left);
}
bool cmpx(point a,point b)
{
    if(a.x!=b.x)
    {
        return a.x<b.x;
    }
    else
    {
        return a.y<b.y;
    }
}
bool cmpy(point a,point b)
{
    if(a.y!=b.y)
    {
        return a.y<b.y;
    }
    else
    {
        return a.x<b.x;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&dat[i].x,&dat[i].y);
    }
    sort(dat,dat+n,cmpx);
    int xn=1;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        if(dat[i].x!=dat[i+1].x)
        {
            flag=1;
        }
        dat[i].x=xn;
        if(flag==1)
        {
            xn++;
        }
    }
    sort(dat,dat+n,cmpy);
    int yn=1;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        if(dat[i].y!=dat[i+1].y)
        {
            flag=1;
        }
        dat[i].y=yn;
        if(flag==1)
        {
            yn++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(zm[dat[i].x]<dat[i].y)
        {
            zm[dat[i].x]=dat[i].y;
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(has[dat[i].x]==0&&dat[i].y!=zm[dat[i].x])
        {
            add(dat[i].x,1);
            has[dat[i].x]=1;
        }
        if(dat[i].y==dat[i+1].y)
        {
            if(dat[i].x!=dat[i+1].x)
            {
                result+=query(dat[i].x+1,dat[i+1].x-1);
            }
        }
        if(has[dat[i].x]==1&&dat[i].y==zm[dat[i].x])
        {
            has[dat[i].x]=0;
            add(dat[i].x,-1);
        }
    }
    printf("%d\n",result+n);
    return 0;
}