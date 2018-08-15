//直接的多重背包问题，dp[i]代表能否到达i的高度，将砖块按能达到的最高高度排序后直接dp即可
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct block
{
    int alti,height,num;
};
block dat[420];
bool cmp(block a,block b)
{
    return a.alti<b.alti;
}
int dp[40010],used[40010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].height>>dat[i].alti>>dat[i].num;
    }
    sort(dat+1,dat+1+n,cmp);
    int max=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));        
        for(int j=dat[i].height;j<=dat[i].alti;j++)
        {
            if(!dp[j]&&dp[j-dat[i].height]&&((used[j-dat[i].height]+1)<=dat[i].num))
            {
                dp[j]=1;
                used[j]=used[j-dat[i].height]+1;
                if(j>max)
                {
                    max=j;
                }
            }
        }
    }
    cout<<max<<endl;
    return 0;
}