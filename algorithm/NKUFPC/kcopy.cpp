#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
const int INF=1e9+9;
vector<int> G[100020];
int tim[100020],sumtime[100020];
bool isleaf[100020];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int extranum=n+1;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&tim[i]);
    }
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[b].push_back(a);
        isleaf[a]=true;
    }
    queue<pair<int,int>> que;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(!isleaf[i])
        {
            ans=max(ans,tim[i]);
            sumtime[i]=tim[i];
            for(int j=0;j<G[i].size();++j)
            {
                if(sumtime[G[i][j]]<(sumtime[i]+tim[G[i][j]]))
                {
                    que.push(make_pair(G[i][j],tim[i]));
                    sumtime[G[i][j]]=sumtime[i]+tim[G[i][j]];
                    ans=max(ans,sumtime[G[i][j]]);
                }
            }
        }
    }
    while(!que.empty())
    {
        pair<int,int> tmp=que.front();
        que.pop();
        for(int j=0;j<G[tmp.first].size();++j)
        {
            if(sumtime[G[tmp.first][j]]<(sumtime[tmp.first]+tim[G[tmp.first][j]]))
            {
                que.push(make_pair(G[tmp.first][j],sumtime[tmp.first]));
                sumtime[G[tmp.first][j]]=sumtime[tmp.first]+tim[G[tmp.first][j]];
                ans=max(ans,sumtime[G[tmp.first][j]]);
            }
        }
    }
    if(ans>604800)
    {
        printf("gugugu\n");
    }
    else
    {
        printf("Don't worry!\n");
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;++i)
    {
        if(i!=1)
        {
            printf(" ");
        }
        printf("%d",ans-sumtime[i]);
    }
    printf("\n");
    return 0;
}