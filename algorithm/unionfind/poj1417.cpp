#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=3020;
int par[MAXN];
void init(int n)
{
    memset(par,-1,sizeof(par));
}
int find(int x)
{
    if(par[x]==-1)
    {
        return x;
    }
    return par[x]=find(par[x]);
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y)
{
    if(same(x,y))
    {
        return;
    }
    x=find(x);
    y=find(y);
    par[x]=y;
}
int sat[1200];
int dp[1200][600];
int main()
{
    int n,p1,p2;
    while(~scanf("%d%d%d",&n,&p1,&p2),n+p1+p2)
    {
        init((p1+p2)*2);
        int sum=p1+p2;
        for(int i=0;i<n;++i)
        {
            char ans[10];
            int a,b;
            scanf("%d%d%s",&a,&b,ans);
            if(ans[0]=='y')
            {
                unite(a,b);
                unite(a+sum,b+sum);
            }
            else
            {
                unite(a,b+sum);
                unite(a+sum,b);
            }
        }
        vector<int> cnt[1020][2];
        memset(sat,0,sizeof(sat));
        int num=1;
        for(int i=1;i<=sum;++i)
        {
            int root=find(i),ref=find(i+sum);
            if(sat[root]==0)
            {
                sat[root]=num;
                sat[ref]=-num;
                ++num;
            }
            if(sat[root]>0)
            {
                cnt[sat[root]][0].push_back(i);
            }
            else
            {
                cnt[sat[ref]][1].push_back(i);
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<num;++i)
        {
            for(int j=0;j<=p1;++j)
            {
                if(j>=cnt[i][0].size())
                {
                    dp[i][j]+=dp[i-1][j-cnt[i][0].size()];
                }
                if(j>=cnt[i][1].size())
                {
                    dp[i][j]+=dp[i-1][j-cnt[i][1].size()];
                }
            }
        }
        if(dp[num-1][p1]==1)
        {
            vector<int> ans;
            int tmp=p1;
            for(int i=num-1;i>0;--i)
            {
                if(dp[i-1][tmp-cnt[i][0].size()]==1)
                {
                    tmp-=cnt[i][0].size();
                    ans.insert(ans.end(),cnt[i][0].begin(),cnt[i][0].end());
                }
                else
                {
                    tmp-=cnt[i][1].size();
                    ans.insert(ans.end(),cnt[i][1].begin(),cnt[i][1].end());
                }
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();++i)
            {
                printf("%d\n",ans[i]);
            }
            printf("end\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}