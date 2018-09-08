//这个是这题的线段树解法···emmmmmmmm大概算是看懂了吧···
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int SIZE=(1<<18)-1;
int N,Q;
int A[100010];
char T[100010];
int L[100010],R[100010],X[100010];
ll dataa[SIZE],datb[SIZE];
void add(int a,int b,int x,int k,int l,int r)
{
    if(a<=l&&r<=b)
    {
        dataa[k]+=x;
    }
    else if(l<b&&a<r)
    {
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
ll sum(int a,int b,int k,int l,int r)
{
    if(b<=l||r<=a)
    {
        return 0;
    }
    else if(a<=l&&r<=b)
    {
        return dataa[k]*(r-l)+datb[k];
    }
    else 
    {
        ll res=(min(b,r)-max(a,l))*dataa[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}
void solve()
{
    for(int i=0;i<N;i++)
    {
        add(i,i+1,A[i],0,0,N);
    }
    for(int i=0;i<Q;i++)
    {
        if(T[i]=='C')
        {
            add(L[i],R[i]+1,X[i],0,0,N);
        }
        else
        {
            printf("%lld\n",sum(L[i],R[i]+1,0,0,N));
        }
    }
}
int main()
{
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<Q;i++)
    {
        char tmp;
        cin>>tmp;
        T[i]=tmp;
        if(tmp=='C')
        {
            scanf("%d%d%d",&L[i],&R[i],&X[i]);
            L[i]--;
            R[i]--;
        }
        else
        {
            scanf("%d%d",&L[i],&R[i]);
            L[i]--;
            R[i]--;
        }
    }
    solve();
    return 0;
}