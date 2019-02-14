#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
#include<cstdio>
using namespace std;
vector<int> edge[100020];
bool arrived[100020],used[100020];
int seq[100020];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==v)
        {
            continue;
        }
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    priority_queue<int,vector<int>,greater<int>> que;
    arrived[1]=true;
    int num=1;
    seq[0]=1;
    for(int i=0;i<edge[1].size();++i)
    {
        if(!used[edge[1][i]])
        {
            que.push(edge[1][i]);
            used[edge[1][i]]=1;
        }
    }
    while(!que.empty()){
        while(arrived[que.top()]!=0)
        {
            que.pop();
        }
        int tmp=que.top();
        que.pop();
        seq[num++]=tmp;
        arrived[tmp]=1;
        for(int i=0;i<edge[tmp].size();++i)
        {
            if((!arrived[edge[tmp][i]])&&(!used[edge[tmp][i]]))
            {
                que.push(edge[tmp][i]);
                used[edge[tmp][i]]=1;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            printf("%d",seq[0]);
        }
        else
        {
            printf(" %d",seq[i]);
        }
    }
    printf("\n");
    return 0;
}