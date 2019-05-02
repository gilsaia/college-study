#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=30020;
const double MAXD=1e9;
struct edge
{
    double x,y;
    bool operator<(edge b)
    {
        if(y==b.y)
        {
            return x<b.x;
        }
        return y<b.y;
    }
};
bool cmpx(edge a,edge b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}
bool cmpy(edge a,edge b)
{
    if(a.y==b.y)
    {
        return a.x<b.x;
    }
    return a.y<b.y;
}
double dis(edge a,edge b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
edge datx[MAXN],daty[MAXN],tocal[MAXN];
int n;
void mmerge(int start,int b,int end)
{
    int pos=start,bea=start,beb=b;
    while(bea<b&&beb<end)
    {
        if(datx[bea]<datx[beb])
        {
            daty[pos++]=datx[bea++];
        }
        else
        {
            daty[pos++]=datx[beb++];
        }
    }
    while(bea<b)
    {
        daty[pos++]=datx[bea++];
    }
    while(beb<end)
    {
        daty[pos++]=datx[beb++];
    }
    for(int i=start;i<end;++i)
    {
        datx[i]=daty[i];
    }
    return;
}
double dividemerge(int start,int end)
{
    if((end-start)<=3)
    {
        double anstmp=MAXD;
        for(int i=start;i<end;++i)
        {
            for(int j=i+1;j<end;++j)
            {
                anstmp=min(anstmp,dis(datx[i],datx[j]));
            }
        }
        for(int i=start;i<end;++i)
        {
            for(int j=i+1;j<end;++j)
            {
                if(datx[i].y>datx[j].y)
                {
                    edge tmp=datx[i];
                    datx[i]=datx[j];
                    datx[j]=tmp;
                }
            }
        }
        return anstmp;
    }
    int a=(start+end)/2-1,b=a+1;
    double line=(datx[a].x+datx[b].x)/2;
    double ans=MAXD;
    ans=min(ans,dividemerge(start,b));
    ans=min(ans,dividemerge(b,end));
    mmerge(start,b,end);
    double linlow=line-ans,linhig=line+ans;
    int num=0;
    for(int i=start;i<end;++i)
    {
        if(datx[i].x>=linlow&&datx[i].x<=linhig)
        {
            tocal[num++]=datx[i];
        }
    }
    for(int i=0;i<num;++i)
    {
        for(int j=i+1;j<(i+8)&&j<num;++j)
        {
            ans=min(ans,dis(tocal[i],tocal[j]));
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        double tmpx,tmpy;
        scanf("%lf%lf",&tmpx,&tmpy);
        datx[i].x=tmpx,datx[i].y=tmpy;
    }
    sort(datx,datx+n,cmpx);
    double ans=dividemerge(0,n);
    printf("%.2lf\n",ans);
    return 0;
}