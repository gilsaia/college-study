#include <cstdio>
#include <vector>
#include <cstring>
#include<algorithm>
#include <queue>
using namespace std;
const int MAXV = 20050;
const int maxm=100050;
const int INF = 1<<30;
int edge;
int level[MAXV];
int iter[MAXV]; //当前弧，之前的已经没有用了
int head[MAXV];
struct edgenode
{
    int from;
    int to;//边的指向
    int cap;//边的容量
    int next;//链表的下一条边
} edges[maxm];
void init()
{
    edge=0;
    memset(head,-1,sizeof(head));
}
void addedge(int from, int to, int cap) {
    edges[edge].from=from;
    edges[edge].cap=cap;
    edges[edge].to=to;
    edges[edge].next=head[from];
    head[from]=edge++;
    edges[edge].from=to;
    edges[edge].cap=0;
    edges[edge].to=from;
    edges[edge].next=head[to];
    head[to]=edge++;
}

void bfs(int s) {
    memset(level, -1, sizeof level);
    std::queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = head[v]; i !=-1; i=edges[i].next) {
            edgenode &e = edges[i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    if(iter[v]==0)
    {
        iter[v]=head[v];
    }
    for (int &i = iter[v]; i !=-1; i=edges[i].next) { // 注意i是引用 实现当前弧优化
        edgenode &e = edges[i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, std::min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                edges[i^1].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    for (; ;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}
int row[120][120],col[120][120],name[120][120],pos;
int todigit(char *dig)
{
    return (dig[0]-'0')*100+(dig[1]-'0')*10+(dig[2]-'0');
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(row,-1,sizeof(row));
        memset(col,-1,sizeof(col));
        memset(name,-1,sizeof(name));
        init();
        pos=0;
        char item[10];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scanf("%s",item);
                if(item[0]=='.')
                {
                    name[i][j]=pos;
                    addedge(pos*2,pos*2+1,8);
                    pos++;
                }
                else
                {
                    if(item[0]!='X')
                    {
                        col[i][j]=todigit(&item[0]);
                    }
                    if(item[4]!='X')
                    {
                        row[i][j]=todigit(&item[4]);
                    }
                }
            }
        }
        int start=pos*2,end=pos*2+1,cons=pos*2+2;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(row[i][j]!=-1)
                {
                    int cotmp=j+1,num=0;
                    while(cotmp<m&&name[i][cotmp]!=-1)
                    {
                        addedge(cons,name[i][cotmp]*2,INF);
                        ++cotmp,++num;
                    }
                    addedge(start,cons,row[i][j]-num);
                    ++cons;
                }
                if(col[i][j]!=-1)
                {
                    int rotmp=i+1,num=0;
                    while(rotmp<n&&name[rotmp][j]!=-1)
                    {
                        addedge(name[rotmp][j]*2+1,cons,INF);
                        ++rotmp,++num;
                    }
                    addedge(cons,end,col[i][j]-num);
                    ++cons;
                }
            }
        }
        int ans=maxflow(start,end);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(name[i][j]==-1)
                {
                    printf("_ ");
                }
                else
                {
                    printf("%d ",9-edges[name[i][j]*2].cap);
                }
            }
            printf("\n");
        }
    }
    return 0;
}