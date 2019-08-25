#include<cstdio>
#include<algorithm>
using namespace std;
int floyd[120][120];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a,--b;
        floyd[a][b]=1;
    }
    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                floyd[i][j]|=(floyd[i][k]&floyd[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int cnt=0;
        for(int j=0;j<n;++j)
        {
            if(floyd[i][j]||floyd[j][i])
            {
                ++cnt;
            }
        }
        if(cnt==n-1)
        {
            ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}