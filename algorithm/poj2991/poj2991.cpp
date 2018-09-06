//线段树的例题···思路想了半天算是看懂了···但是好诡啊好诡啊好诡啊···
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int SIZE=(1<<15)-1;
const double PI=3.1415926535;
int N,C;
int L[10020];
int S[10020],A[10020];
double vx[SIZE],vy[SIZE];
double ang[SIZE];
double pre[10020];
void init(int k,int l,int r)
{
    ang[k]=vx[k]=0.0;
    if(r-l==1)
    {
        vy[k]=L[l];
    }
    else
    {
        int chl=k*2+1,chr=k*2+2;
        init(chl,l,(l+r)/2);
        init(chr,(l+r)/2,r);
        vy[k]=vy[chl]+vy[chr];
    }
}
void change(int s,double a,int v,int l,int r)
{
    if(s<=l)
    {
        return;
    }
    else if(s<r)
    {
        int chl=v*2+1,chr=v*2+2;
        int m=(l+r)/2;
        change(s,a,chl,l,m);
        change(s,a,chr,m,r);
        if(s<=m)
        {
            ang[v]+=a;
        }
        double s=sin(ang[v]),c=cos(ang[v]);
        vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
        vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);
    }
}
void solve()
{
    init(0,0,N);
    for(int i=1;i<N;i++)
    {
        pre[i]=PI;
    }
    for(int i=0;i<C;i++)
    {
        int s=S[i];
        double a=A[i]/360.0*2*PI;
        change(s,a-pre[s],0,0,N);
        pre[s]=a;
        printf("%.2f %.2f\n",vx[0],vy[0]);
    }
}
int main()
{
    while(cin>>N>>C)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d",&L[i]);
        }
        for(int i=0;i<C;i++)
        {
            scanf("%d%d",&S[i],&A[i]);
        }
        solve();
        printf("\n");
    }
    return 0;
}