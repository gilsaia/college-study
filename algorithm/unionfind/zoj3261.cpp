#include<cstdio>
#include<algorithm>
#include<set>
#include<utility>
using namespace std;
const int MAXN=30020;
int par[MAXN],val[MAXN];
void init(int n)
{
    for(int i=0;i<=n;++i)
    {
        par[i]=i;
    }
}
int find(int x)
{
    if(x==par[x])
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
    x=find(x);
    y=find(y);
    if(val[x]>val[y])
    {
        par[y]=x;
    }
    else if(val[x]<val[y])
    {
        par[x]=y;
    }
    else if(x<y)
    {
        par[y]=x;
    }
    else
    {
        par[x]=y;
    }
}
pair<int,int> pat[20020];
int con[50020][3];
int ans[50020];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init(n);
        set<pair<int,int>> todes;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&val[i]);
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&pat[i].first,&pat[i].second);
            if(pat[i].first>pat[i].second)
            {
                swap(pat[i].first,pat[i].second);
            }
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;++i)
        {
            char tmp[20];
            scanf("%s",tmp);
            if(tmp[0]=='d')
            {
                con[i][0]=1;
                scanf("%d%d",&con[i][1],&con[i][2]);
                if(con[i][1]>con[i][2])
                {
                    swap(con[i][1],con[i][2]);
                }
                todes.insert(pair<int,int>(con[i][1],con[i][2]));
            }
            else
            {
                con[i][0]=0;
                scanf("%d",&con[i][1]);
            }
        }
        for(int i=0;i<m;++i)
        {
            if(todes.find(pat[i])==todes.end())
            {
                unite(pat[i].first,pat[i].second);
            }
        }
        for(int i=q-1;i>=0;--i)
        {
            if(con[i][0]==0)
            {
                int tofind=find(con[i][1]);
                if(tofind==con[i][1])
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=tofind;
                }
            }
            else
            {
                unite(con[i][1],con[i][2]);
            }
        }
        for(int i=0;i<q;++i)
        {
            if(con[i][0]==0)
            {
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}