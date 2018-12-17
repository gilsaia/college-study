#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> G[100020];
int tim[100020],sumtime[100020],counttime[100020],showtime[100020];
bool isleaf[100020];
inline int max(const int &a,const int &b)
{
    return a>b?a:b;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&tim[i]);
    }
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[b].push_back(a);
        showtime[a]++;
        isleaf[a]=1;
    }
    queue<int> que;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(!isleaf[i])
        {
            ans=max(ans,tim[i]);
            sumtime[i]=tim[i];
            que.push(i);
        }
    }
    while(!que.empty())
    {
        int tmp=que.front();
        que.pop();
        for(int j=0;j<G[tmp].size();++j)
        {
            counttime[G[tmp][j]]++;
            if(counttime[G[tmp][j]]==showtime[G[tmp][j]])
            {
                que.push(G[tmp][j]);
            }
            if(sumtime[G[tmp][j]]<(sumtime[tmp]+tim[G[tmp][j]]))
            {
                sumtime[G[tmp][j]]=sumtime[tmp]+tim[G[tmp][j]];
                ans=max(ans,sumtime[G[tmp][j]]);
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