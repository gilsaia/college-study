#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
using namespace std;
long long summatrix[4050][4050];
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=M;++j)
        {
            long long  tmp;
            scanf("%lld",&tmp);
            summatrix[i][j]=summatrix[i][j-1]+tmp;
            summatrix[i][j-1]+=summatrix[i-1][j-1];
        }
        summatrix[i][M]+=summatrix[i-1][M];
    }
    int k1,k2;
    scanf("%d%d",&k1,&k2);
    long long ans=0;
    for(int i=1;i<=k1;++i)
    {
        for(int j=1;j<=k2;++j)
        {
           ans=max(ans,summatrix[i][j]);
           if(j<=M)
           {
                long long rightup=summatrix[i][M]-summatrix[i][M-j];
                ans=max(ans,rightup);
           }
            if(i<=N)
            {
                long long leftdown=summatrix[N][j]-summatrix[N-i][j];
                ans=max(ans,leftdown);
            }
            if(j<=M&&i<=N)
            {
                long long rightdown=summatrix[N][M]-summatrix[N][M-j]-summatrix[N-i][M]+summatrix[N-i][M-j];
                ans=max(ans,rightdown);
            }
        }
    }
    for(int i=k1;i<=N;++i)
    {
        for(int j=k2;j<=M;++j)
        {
            long long tmp=summatrix[i][j]-summatrix[i][j-k2]-summatrix[i-k1][j]+summatrix[i-k1][j-k2];
            ans=max(ans,tmp);
        }
    }
    for(int i=k1;i<=N;++i)
    {
        for(int j=1;j<=k2;++j)
        {
            long long tmp=summatrix[i][j]-summatrix[i-k1][j];
            ans=max(ans,tmp);
            if(j<=M)
            {
                long long right=summatrix[i][M]-summatrix[i][M-j]-summatrix[i-k1][M]+summatrix[i-k1][M-j];
                ans=max(ans,right);
            }
        }
    }
    for(int j=k2;j<=M;++j)
    {
        for(int i=1;i<=k1;++i)
        {
            long long tmp=summatrix[i][j]-summatrix[i][j-k2];
            ans=max(ans,tmp);
            if(i<=N)
            {
                long long down=summatrix[N][j]-summatrix[N][j-k2]-summatrix[N-i][j]+summatrix[N-i][j-k2];
                ans=max(ans,down);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}