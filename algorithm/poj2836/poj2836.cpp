//状压dp题···自己写的直接tle了···看了看题解发现是dp思路错了···懒得改了就抄的题解···
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
 
using namespace std;
 
const int MAXN = 15;
const int INF = 0x3f3f3f3f;
 
struct POINT
{
    int x;
    int y;
} p[MAXN + 1];
 
struct RECTANGLE
{
    int area;
    int cover;
} r[MAXN * MAXN];
 
int n;
int dp[1 << MAXN];
int area[MAXN + 1][MAXN + 1];
int cnt;
 
 
void Read()
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
}
 
void Init()
{
    cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (j != i)
            {
                int width = abs(p[i].x - p[j].x) == 0 ? 1 : abs(p[i].x - p[j].x);
                int height = abs(p[i].y - p[j].y) == 0 ? 1 : abs(p[i].y - p[j].y);
                r[cnt].area = width * height;
                r[cnt].cover = 0;
                for (int k = 0; k < n; ++k)
                {
                    if (p[k].x >= min(p[i].x, p[j].x) && p[k].x <= max(p[i].x, p[j].x) &&
                            p[k].y >= min(p[i].y, p[j].y) && p[k].y <= max(p[i].y, p[j].y))
                    {
                        r[cnt].cover |= (1 << k);
                    }
                }
                ++cnt;
            }
        }
    }
}
 
void Dp()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int S = 0; S < (1 << n); ++S)
    {
        if (dp[S] != INF)
        {
            for (int i = 0; i < cnt; ++i)
            {
                int news = S | r[i].cover;
                if (news != S)
                {
                    dp[news] = min(dp[news], dp[S] + r[i].area);
                }
            }
        }
    }
    printf("%d\n", dp[(1 << n) - 1]);
}
 
int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        Read();
        Init();
        Dp();
    }
 
    return 0;
}
/*#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9;
struct point
{
    int maxx,maxy,minx,miny;
    int area;
}dp[1<<15];
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&dp[1<<i].maxx,&dp[1<<i].maxy);
            dp[1<<i].minx=dp[1<<i].maxx;
            dp[1<<i].miny=dp[1<<i].maxy;
            dp[1<<i].area=1;
        }
        for(int i=2;i<=n;i++)
        {
            int comb=(1<<i)-1;
            while(comb<1<<n)
            {
                dp[comb].area=INF;
                dp[comb].minx=INF;
                dp[comb].miny=INF;
                dp[comb].maxx=-INF;
                dp[comb].maxy=-INF;
                for(int s0=(comb-1)&comb;s0>=(comb&(~s0));s0=(s0-1)&comb)
                {
                    dp[comb].maxx=max(dp[s0].maxx,dp[comb].maxx);
                    dp[comb].maxy=max(dp[s0].maxy,dp[comb].maxy);
                    dp[comb].minx=min(dp[s0].minx,dp[comb].minx);
                    dp[comb].miny=min(dp[s0].miny,dp[comb].miny);
                    dp[comb].area=min(dp[comb].area,dp[s0].area+dp[comb&(~s0)].area);
                }
                if(dp[comb].maxx==dp[comb].minx)
                {
                    dp[comb].area=min(dp[comb].area,dp[comb].maxy-dp[comb].miny);
                }
                else if(dp[comb].maxy==dp[comb].miny)
                {
                    dp[comb].area=min(dp[comb].area,dp[comb].maxx-dp[comb].minx);
                }
                else
                {
                    dp[comb].area=min(dp[comb].area,(dp[comb].maxx-dp[comb].minx)*(dp[comb].maxy-dp[comb].miny));
                }
                int x=comb&-comb,y=comb+x;
                comb=((comb&~y)/x>>1)|y;
            }
        }
        printf("%d\n",dp[(1<<n)-1].area);
    }
    return 0;
}*/