//开关问题例题···别的问题不大但是scanf读取char还是非常奇怪最后实在懒干脆cin了···
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int N;
int dir[5020];
int f[5020];
int calc(int K)
{
    memset(f,0,sizeof(f));
    int res=0;
    int sum=0;
    for(int i=0;i+K<=N;i++)
    {
        if((dir[i]+sum)%2!=0)
        {
            res++;
            f[i]=1;
        }
        sum+=f[i];
        if(i-K+1>=0)
        {
            sum-=f[i-K+1];
        }
    }
    for(int i=N-K+1;i<N;i++)
    {
        if((dir[i]+sum)%2!=0)
        {
            return -1;
        }
        if(i-K+1>=0)
        {
            sum-=f[i-K+1];
        }
    }
    return res;
}
void solve()
{
    int K=1,M=N;
    for(int k=1;k<=N;k++)
    {
        int m=calc(k);
        if(m>=0&&M>m)
        {
            M=m;
            K=k;
        }
    }
    printf("%d %d\n",K,M);
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        char temp;
        cin>>temp;
        if(temp=='B')
        {
            dir[i]=1;
        }
        else
        {
            dir[i]=0;
        }
    }
    solve();
    return 0;
}