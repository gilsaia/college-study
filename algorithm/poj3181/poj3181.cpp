//多重背包dp问题还有解决大数问题
//递归思路上dp[i][j]为i元在前j种工具中的组合数，它包含两部分，含有j工具的部分和不含有j工具的部分
//不含j的部分为dp[i][j-1]，含有j的部分可以考虑作去掉一个j工具后即为i-j元的情况即dp[i-j][j]，所以dp[i][j]=dp[i][j-1]+dp[i-j][j]
//由于题目数据限制long long也不够所以用了分解大数的办法，以上全是从题解看的··
#include<iostream>
using namespace std;
long long dpa[1020][120],dpb[1020][120],inf=1e18;
int main()
{
    dpb[1][1]=1;
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=K;j++)
        {
            if(j==i)
            {
                dpb[i][j]=(dpb[i][j-1]+1)%inf;
                dpa[i][j]=(dpb[i][j-1])/inf+dpa[i][j-1];
            }
            else if(j>i)
            {
                dpa[j][j]=dpa[i][j-1];
                dpb[i][j]=dpb[i][j-1];
            }
            else
            {
                dpa[i][j]=dpa[i][j-1]+dpa[i-j][j]+(dpb[i][j-1]+dpb[i-j][j])/inf;
                dpb[i][j]=(dpb[i][j-1]+dpb[i-j][j])%inf;
            }
        }
    }
    if(dpa[N][K])
    cout<<dpa[N][K];
    cout<<dpb[N][K]<<endl;
    return 0;
}