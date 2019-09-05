#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1020;
const int MAXM=1<<15;
struct Line
{
    double x1,x2,y;
    int setv;
    Line(double _x1=0,double _x2=0,double _y=0,int _setv=0):x1(_x1),x2(_x2),y(_y),setv(_setv){}
    bool operator<(const Line &rhs) const
    {
        if(y==rhs.y)
        {
            return setv>rhs.setv;
        }
        return y<rhs.y;
    }
};
Line line[MAXN*2];
int cnt[MAXM];
double sum[MAXM],all[MAXM];
void pushup(int rt,int l,int r)
{
    if(cnt[rt])
    {
        sum[rt]=all[r+1]-all[l];
    }
    else if(l==r)
    {
        sum[rt]=0;
    }
    else
    {
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    }
}
void update(int rt,int l,int r,int ql,int qr,int setv)
{
    if(ql<=l&&qr>=r)
    {
        cnt[rt]+=setv;
        pushup(rt,l,r);
        return;
    }
    int m=(l+r)>>1;
    if(ql<=m)
    {
        update(rt<<1,l,m,ql,qr,setv);
    }
    if(qr>m)
    {
        update(rt<<1|1,m+1,r,ql,qr,setv);
    }
    pushup(rt,l,r);
}
int main()
{
    int n,num=1;
    while(~scanf("%d",&n),n)
    {
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;++i)
        {
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            line[i]=Line(x1,x2,y1,1);
            line[i+n]=Line(x1,x2,y2,-1);
            all[i]=x1,all[i+n]=x2;
        }
        n<<=1;
        sort(line+1,line+1+n);
        sort(all+1,all+n+1);
        int m=unique(all+1,all+n+1)-all-1;
        double ans=0;
        for(int i=1;i<n;++i)
        {
            int l=lower_bound(all+1,all+1+m,line[i].x1)-all;
            int r=lower_bound(all+1,all+1+m,line[i].x2)-all;
            if(l<r)
            {
                update(1,1,m,l,r-1,line[i].setv);
            }
            ans+=sum[1]*(line[i+1].y-line[i].y);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",num,ans);
        ++num;
    }
    return 0;
}