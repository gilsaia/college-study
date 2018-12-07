#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
using namespace std;
long long save[3050][3050];
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>save[i][j];
        }
    }
    int k1,k2;
    cin>>k1>>k2;
    long long ans=0;
    long long tmpe=0;
    for(int i=0;i<k1;++i)
    {
        for(int j=0;j<k2;++j)
        {
            tmpe+=save[i][j];
        }
    }
    ans=max(ans,tmpe);
    long long laststart=ans;
    for(int i=k1;i<N+k1;++i)
    {
        long long tmpans=laststart;
        for(int j=k2;j<M+k2;++j)
        {
            for(int t=i-1;t>=i-k1;--t)
            {
                tmpans-=save[t][j-k2];
                tmpans+=save[t][j];
            }
            ans=max(ans,tmpans);
        }
        for(int t=k2-1;t>=0;--t)
        {
            laststart-=save[i-k1][t];
            laststart+=save[i][t];
        }
        ans=max(ans,laststart);
    }
    swap(k1,k2);
    tmpe=0;
    for(int i=0;i<k1;++i)
    {
        for(int j=0;j<k2;++j)
        {
            tmpe+=save[i][j];
        }
    }
    ans=max(ans,tmpe);
    laststart=tmpe;
    for(int i=k1;i<N+k1;++i)
    {
        long long tmpans=laststart;
        for(int j=k2;j<M+k2;++j)
        {
            for(int t=i-1;t>=i-k1;--t)
            {
                tmpans-=save[t][j-k2];
                tmpans+=save[t][j];
            }
            ans=max(ans,tmpans);
        }
        for(int t=k2-1;t>=0;--t)
        {
            laststart-=save[i-k1][t];
            laststart+=save[i][t];
        }
        ans=max(ans,laststart);
    }
    cout<<ans<<endl;
    return 0;
}