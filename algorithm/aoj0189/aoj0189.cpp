//基础的多源最短路问题，按模板套即可，注意结果如果有相同的要求输出最小编号而不是全部··
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int d[12][12];
int V;
const int INF=100000000;
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        for(int i=0;i<=11;i++)
        {
            for(int j=0;j<12;j++)
            {
                d[i][j]=INF;
            }
        }
        for(int i=0;i<=11;i++)
        {
            d[i][i]=0;
        }
        int t=0;
        for(int i=0;i<n;i++)
        {
            int a,b,cost;
            scanf("%d%d%d",&a,&b,&cost);
            d[a][b]=cost;
            d[b][a]=cost;
            if(a>t)
            {
                t=a;
            }
            if(b>t)
            {
                t=b;
            }
        }
        for(int k=0;k<=t;k++)
        {
            for(int i=0;i<=t;i++)
            {
                for(int j=0;j<=t;j++)
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        vector<int> site;
        int ans=INF;
        for(int i=0;i<=t;i++)
        {
            int temp=0;
            for(int j=0;j<=t;j++)
            {
                temp+=d[i][j];
            }
            if(temp<ans)
            {
                ans=temp;
                site.clear();
                site.push_back(i);
            }
            else if(temp>ans)
            {
                continue;
            }
        }
        for(int i=0;i<site.size();i++)
        {
            printf("%d ",site[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}