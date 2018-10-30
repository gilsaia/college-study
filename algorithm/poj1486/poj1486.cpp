#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=300;
int n;
bool G[maxn][maxn];
int res[maxn],match[maxn];
bool used[maxn];
struct rec
{
    int minx,miny,maxx,maxy;
}recs[30];
struct point
{
    int x,y;
}points[30];
bool OK(const rec &re,const point &p)
{
    return(p.x>re.minx&&p.x<re.maxx&&p.y>re.miny&&p.y<re.maxy);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=n;i<2*n;++i)
    {
        if(!G[v][i])
        {
            continue;
        }
        int u=i,w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int max_match()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<n;++i)
    {
        if(match[i]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(i))
            {
                ++res;
            }
        }
    }
    return res;
}
int main()
{
    for(int k=1;;++k)
    {
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        memset(G,false,sizeof(G));
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d%d",&recs[i].minx,&recs[i].maxx,&recs[i].miny,&recs[i].maxy);
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&points[i].x,&points[i].y);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(OK(recs[i],points[j]))
                {
                    G[i][n+j]=G[n+j][i]=true;
                }
            }
        }
        max_match();
        for(int i=0;i<n;++i)
        {
            res[i]=match[i];
        }
        int cnt=0;
        printf("Heap %d\n",k);
        for(int i=0;i<n;++i)
        {
            G[i][res[i]]=G[res[i]][i]=false;
            if(n==max_match())
            {
                continue;
            }
            else
            {
                if(cnt++>0)
                {
                    printf(" ");
                }
                printf("(%c,%d)",i+'A',res[i]-n+1);
            }
            G[i][res[i]]=G[res[i]][i]=true;
        }
        if(cnt==0)
        {
            printf("none");
        }
        printf("\n\n");
    }
    return 0;
}