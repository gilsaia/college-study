#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int value[4][20][12];
int hand[4][20][2];
int black[90];
int play[12000];
int dp[10020][6];
int main()
{
    int a[4],L;
    memset(dp,-1,sizeof(dp));
    black[2]=1;
    for(int i=4;i<=88;i+=12)
    {
        black[i+1]=black[i+3]=black[i+6]=black[i+8]=black[i+10]=1;
    }
    scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&L);
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<a[i];++j)
        {
            scanf("%d%d",&hand[i][j][0],&hand[i][j][1]);
            for(int t=0;t<12;++t)
            {
                scanf("%d",&value[i][j][t]);
            }
        }
    }
    for(int i=0;i<L;++i)
    {
        scanf("%d",&play[i]);
    }
    int com=0;
    com|(black[play[0]]);
    com|(black[play[1]]<<1);
    
}