//状压dp题···数组开大了会爆内存只能改成循环数组了···
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int dp[2][1<<20];
vector<int> dat[22];
int N,M;
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int tmp;
            scanf("%d",&tmp);
            --tmp;
            dat[i].push_back(tmp);
        }
    }
    int ans=0;
    for(int i=0;i<dat[0].size();i++)
    {
        int tmp=dat[0][i];
        dp[0][1<<tmp]=1;
        ++ans;
    }
    for(int i=1;i<N;i++)
    {
        ans=0;
        memset(dp[i%2],0,sizeof(dp[i%2]));
        for(int j=0;j<(1<<M);j++)
        {
            if(dp[(i-1)%2][j])
            {
                for(int t=0;t<dat[i].size();t++)
                {
                    int tir=dat[i][t];
                    if((j>>tir&1)!=1)
                    {
                        dp[i%2][j|1<<tir]+=dp[(i-1)%2][j];
                        ans+=dp[(i-1)%2][j];
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}