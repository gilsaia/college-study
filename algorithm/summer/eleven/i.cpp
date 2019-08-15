#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int dat[10][10];
int k;
int dfs(int num,int alpha,int beta,int mine,int sum,int x,int y)
{
    int newsum=0;
    if(num)
    {
        for(int i=x;i<=x+1;++i)
        {
            for(int j=y;j<=y+1;++j)
            {
                newsum+=dat[i][j];
            }
        }
        swap(dat[x][y],dat[x+1][y]);
        swap(dat[x][y],dat[x+1][y+1]);
        swap(dat[x][y],dat[x][y+1]);
    }
    if(num==2*k)
    {
        swap(dat[x][y],dat[x][y+1]);
        swap(dat[x][y],dat[x+1][y+1]);
        swap(dat[x][y],dat[x+1][y]);
        return sum+newsum;
    }
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(mine)
            {
                beta=min(beta,dfs(num+1,alpha,beta,mine^1,sum+newsum,i,j));
            }
            else
            {
                alpha=max(alpha,dfs(num+1,alpha,beta,mine^1,sum+newsum,i,j));
            }
            if(beta<=alpha)
            {
                break;
            }
        }
        if(beta<=alpha)
        {
            break;
        }
    }
    swap(dat[x][y],dat[x][y+1]);
    swap(dat[x][y],dat[x+1][y+1]);
    swap(dat[x][y],dat[x+1][y]);
    return mine?beta:alpha;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                scanf("%d",&dat[i][j]);
            }
        }
        int ans=dfs(0,-INF,INF,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}