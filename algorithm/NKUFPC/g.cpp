#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> G[100020];
int tim[100020],sumtime[100020];
bool isleaf[100020];
inline int max(const int &a,const int &b)
{
    return a>b?a:b;
}
/*nline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}*/
int main()
{
    int n,m;
    /*n=read();
    m=read();*/
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        //tim[i]=read();
        scanf("%d",&tim[i]);
    }
    for(int i=0;i<m;++i)
    {
        int a,b;
        /*a=read();
        b=read();*/
        scanf("%d%d",&a,&b);
        G[b].push_back(a);
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
            for(int j=0;j<G[i].size();++j)
            {
                if(sumtime[G[i][j]]<(sumtime[i]+tim[G[i][j]]))
                {
                    que.push(G[i][j]);
                    sumtime[G[i][j]]=sumtime[i]+tim[G[i][j]];
                    ans=max(ans,sumtime[G[i][j]]);
                }
            }
        }
    }
    while(!que.empty())
    {
        int tmp=que.front();
        que.pop();
        for(int j=0;j<G[tmp].size();++j)
        {
            if(sumtime[G[tmp][j]]<(sumtime[tmp]+tim[G[tmp][j]]))
            {
                que.push(G[tmp][j]);
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