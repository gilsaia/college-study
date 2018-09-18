//归类在线段树但实际是差分约束的题······第一次接触差分约束···题解算是看懂了···但是自己抄的总是tle不知道为啥···不想说话···
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn= 50000+10;
const int maxm=500000+10;
#define INF 1e9
 
struct Edge
{
    int from,to,dist;
    Edge(){}
    Edge(int f,int t,int d):from(f),to(t),dist(d){}
};
 
struct SPFA
{
    int n,m;
    int head[maxn],next[maxm];
    Edge edges[maxm];
    int d[maxn];
    bool inq[maxn];
 
    void init()
    {
        m=0;
        memset(head,-1,sizeof(head));
    }
 
    void AddEdge(int from,int to,int dist)
    {
        edges[m]=Edge(from,to,dist);
        next[m]=head[from];
        head[from]=m++;
    }
 
    int spfa()
    {
        memset(inq,0,sizeof(inq));
        for(int i=0;i<n;i++) d[i]= i==0?0:INF;
        queue<int> Q;
        Q.push(0);
 
        while(!Q.empty())
        {
            int u=Q.front(); Q.pop();
            inq[u]=false;
 
            for(int i=head[u];i!=-1;i=next[i])
            {
                Edge &e=edges[i];
                if(d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist;
                    if(!inq[e.to])
                    {
                        inq[e.to]=true;
                        Q.push(e.to);
                    }
                }
            }
        }
        return d[n-1]-d[9];
    }
}SP;
 
int main()
{
    int n,max_v=-1;
    scanf("%d",&n);
    SP.init();
    while(n--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        b+=10,a+=10;//所有值都加10了,以免a-1成为-1
        max_v=max(max_v,b);
        SP.AddEdge(b,a-1,-c);
    }
    for(int i=10;i<=max_v;i++)//从该循环可看出,本差分约束的点编号为:[9,max_v](未包含超级源0号点)
    {
        SP.AddEdge(i,i-1,0);
        SP.AddEdge(i-1,i,1);
        SP.AddEdge(0,i,0);
    }
    SP.AddEdge(0,9,0);
    SP.n=max_v+1;
    printf("%d\n",SP.spfa());//注意最终结果是d[max_v]-d[9]的值,而不是d[max_v]的单独值
    return 0;
}
