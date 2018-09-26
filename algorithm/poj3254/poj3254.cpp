//状压dp的题···这个主要是查了各种奇技淫巧的位运算技巧实现的···
#include<cstdio>
using namespace std;
const int MOD=100000000;
int pos[14],dp[14][1<<12],N,M;
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            pos[i]|=(tmp<<j);
        }
    }
    int last=0;
    for(int i=pos[0];i;i=(i-1)&pos[0])
    {
        if((i>>1)&i)
        {
            continue;
        }
        dp[0][i]=1;
        ++last;
    }
    ++last;
    dp[0][0]=1;
    for(int i=1;i<N;i++)
    {
        dp[i][0]+=last;
        last%=MOD;
        for(int j=pos[i];j;j=(j-1)&pos[i])
        {
            if((j>>1)&j)
            {
                continue;
            }
            for(int t=pos[i-1];t;t=(t-1)&pos[i-1])
            {
                if((t>>1)&t)
                {
                    continue;
                }
                if((j&t)==0)
                {
                    dp[i][j]+=dp[i-1][t];
                    dp[i][j]%=MOD;
                    last+=dp[i-1][t];
                    last%=MOD;
                }
            }
            dp[i][j]+=dp[i-1][0];
            dp[i][j]%=MOD;
            last+=dp[i-1][0];
            last%=MOD;
        }
    }
    printf("%d\n",last);
    return 0;
}