#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> G[1520];
int wex[1520];
int path[1520];
void addedge(int i,int j)
{
    G[i].push_back(j);
    G[j].push_back(i);
}
struct node
{
    int pos,path;
};
int main()
{
    int r,n,a,b,x;
    scanf("%d%d%d%d%d",&r,&n,&a,&b,&x);
    int lastsize=r,sumsize=r;
    for(int i=1;i<r;++i)
    {
        for(int j=1;j<=r+i;++j)
        {
            if(j!=1)
            {
                addedge(sumsize+j,sumsize+j-lastsize-1);
            }
            if(j!=(r+i))
            {
                addedge(sumsize+j,sumsize+j-lastsize);
            }
            if(j!=(r+i))
            {
                addedge(sumsize+j,sumsize+j+1);
            }
        }
        ++lastsize;
        sumsize+=lastsize;
    }
    for(int i=1;i<r;++i)
    {
        for(int j=1;j<=r+r-1-i;++j)
        {
            addedge(sumsize+j,sumsize+j-lastsize);
            addedge(sumsize+j,sumsize+j-lastsize+1);
            if(j!=1)
            {
                addedge(sumsize+j,sumsize+j-1);
            }
        }
        --lastsize;
        sumsize+=lastsize;
    }
    for(int i=0;i<x;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        wex[tmp]=1;
    }
    memset(path,INF,sizeof(path));
    path[a]=0;
    node start;
    start.pos=a,start.path=0;
    queue<node> que;
    que.push(start);
    int ans=-1;
    while(!que.empty())
    {
        node tmp=que.front();
        que.pop();
        if(tmp.path>n)
        {
            continue;
        }
        if(tmp.pos==b)
        {
            ans=tmp.path;
            break;
        }
        for(int i=0;i<G[tmp.pos].size();++i)
        {
            int to=G[tmp.pos][i];
            if(wex[to])
            {
                continue;
            }
            if((tmp.path+1)<path[to])
            {
                path[to]=tmp.path+1;
                node next=tmp;
                next.pos=to;
                ++next.path;
                que.push(next);
            }
        }
    }
    if(ans==-1)
    {
        printf("No\n");
    }
    else
    {
        printf("%d\n",ans);
    }
    return 0;
}