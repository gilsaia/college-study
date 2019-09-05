/*
*HDU 3642
给定一些长方体，求这些长方体相交至少3次的体积
z坐标的绝对值不超过500，所以枚举z坐标，然后求矩形面积并
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN=2010;
struct Node
{
    int l,r;
    int lf,rf;//实际的左右端点
    int c;
    int once,twice,more;
}segTree[MAXN*3];
int y[MAXN];
int z[MAXN];
struct Line
{
    int x;
    int y1,y2;
    int z1,z2;//这两个是枚举的时候判断使用的
    int f;
}line[MAXN];
bool cmp(Line a,Line b)
{
    return a.x<b.x;
}
void Build(int i,int l,int r)
{
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].lf=y[l];
    segTree[i].rf=y[r];
    segTree[i].c=0;
    segTree[i].once=segTree[i].twice=segTree[i].more=0;
    if(r==l+1)return;
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid,r);
}
void push_up(int i)
{
    if(segTree[i].c>2)
    {
        segTree[i].more=segTree[i].rf-segTree[i].lf;
        segTree[i].once=segTree[i].twice=0;
    }
    else if(segTree[i].c==2)
    {
        if(segTree[i].l+1==segTree[i].r)//叶子结点
        {
            segTree[i].more=0;
            segTree[i].twice=segTree[i].rf-segTree[i].lf;
            segTree[i].once=0;
            return;
        }
        segTree[i].more=segTree[i<<1].once+segTree[i<<1].twice+segTree[i<<1].more
                       +segTree[(i<<1)|1].once+segTree[(i<<1)|1].twice+segTree[(i<<1)|1].more;
        segTree[i].twice=segTree[i].rf-segTree[i].lf-segTree[i].more;
        segTree[i].once=0;
    }
    else if(segTree[i].c==1)
    {
        if(segTree[i].l+1==segTree[i].r)
        {
            segTree[i].more=0;
            segTree[i].twice=0;
            segTree[i].once=segTree[i].rf-segTree[i].lf;
            return;
        }
        segTree[i].more=segTree[i<<1].more+segTree[i<<1].twice
                    +segTree[(i<<1)|1].more+segTree[(i<<1)|1].twice;
        segTree[i].twice=segTree[i<<1].once+segTree[(i<<1)|1].once;
        segTree[i].once=segTree[i].rf-segTree[i].lf-segTree[i].more-segTree[i].twice;
    }
    else
    {
        if(segTree[i].l+1==segTree[i].r)
        {
            segTree[i].more=segTree[i].once=segTree[i].twice=0;
            return;
        }
        segTree[i].more=segTree[i<<1].more+segTree[(i<<1)|1].more;
        segTree[i].twice=segTree[i<<1].twice+segTree[(i<<1)|1].twice;
        segTree[i].once=segTree[i<<1].once+segTree[(i<<1)|1].once;
    }
}
void update(int i,Line e)
{
    if(segTree[i].lf>=e.y1 && segTree[i].rf<=e.y2)
    {
        segTree[i].c+=e.f;
        push_up(i);
        return;
    }
    if(e.y2<=segTree[i<<1].rf) update(i<<1,e);
    else if(e.y1>=segTree[(i<<1)|1].lf) update((i<<1)|1,e);
    else
    {
        Line temp=e;
        temp.y2=segTree[i<<1].rf;
        update(i<<1,temp);
        temp=e;
        temp.y1=segTree[(i<<1)|1].lf;
        update((i<<1)|1,temp);
    }
    push_up(i);
}
Line temp[MAXN];
int main()
{
    int T;
    int n;
    int x1,y1,z1,x2,y2,z2;
    scanf("%d",&T);
    int iCase=0;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        int t=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
            line[t].x=x1;
            line[t].y1=y1;
            line[t].y2=y2;
            line[t].z1=z1;
            line[t].z2=z2;
            line[t].f=1;
            y[t]=y1;
            z[t++]=z1;

            line[t].x=x2;
            line[t].y1=y1;
            line[t].y2=y2;
            line[t].z1=z1;
            line[t].z2=z2;
            line[t].f=-1;
            y[t]=y2;
            z[t++]=z2;
        }
        sort(line,line+t,cmp);
        sort(y,y+t);
        int t1=unique(y,y+t)-y;
        Build(1,0,t1-1);
        sort(z,z+t);
        int t2=unique(z,z+t)-z;
        long long ans=0;
        long long area=0;
        for(int i=0;i<t2-1;i++)
        {
            int m=0;
            for(int j=0;j<t;j++)
              if(line[j].z1<=z[i]&&line[j].z2>z[i])
                 temp[m++]=line[j];
            area=0;
            update(1,temp[0]);
            for(int j=1;j<m;j++)
            {
                area+=(long long)segTree[1].more*(temp[j].x-temp[j-1].x);
                update(1,temp[j]);
            }
            ans+=area*(z[i+1]-z[i]);
        }
        printf("Case %d: %I64d\n",iCase,ans);
    }
    return 0;
}