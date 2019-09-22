#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30020;
int par[MAXN];
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
    par[x]=y;
}
int con[2030][3];
bool isjudge[1020];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<m;++i)
        {
            char tmp;
            scanf("%d%c%d",&con[i][0],&tmp,&con[i][1]);
            if(tmp=='<')
            {
                con[i][2]=1;
            }
            else if(tmp=='>')
            {
                con[i][2]=2;
            }
            else
            {
                con[i][2]=0;
            } 
        }
        int maxjudge=0,findwro=0;
        for(int i=0;i<n;++i)
        {
            init(n*3);
            isjudge[i]=true;
            for(int j=0;j<m;++j)
            {
                if(con[j][0]==i||con[j][1]==i)
                {
                    continue;
                }
                if(con[j][2]==0)
                {
                    if(same(con[j][0],con[j][1]+n)||same(con[j][0],con[j][1]+n*2))
                    {
                        ++findwro;
                        isjudge[i]=false;
                        maxjudge=max(j+1,maxjudge);
                        break;
                    }
                    unite(con[j][0],con[j][1]);
                    unite(con[j][0]+n,con[j][1]+n);
                    unite(con[j][0]+n*2,con[j][1]+n*2);
                }
                else if(con[j][2]==1)
                {
                    if(same(con[j][0],con[j][1])||same(con[j][0],con[j][1]+n*2))
                    {
                        ++findwro;
                        isjudge[i]=false;
                        maxjudge=max(j+1,maxjudge);
                        break;
                    }
                    unite(con[j][0],con[j][1]+n);
                    unite(con[j][0]+n,con[j][1]+n*2);
                    unite(con[j][0]+n*2,con[j][1]);
                }
                else if(con[j][2]==2)
                {
                    if(same(con[j][0],con[j][1])||same(con[j][0],con[j][1]+n))
                    {
                        ++findwro;
                        isjudge[i]=false;
                        maxjudge=max(j+1,maxjudge);
                        break;
                    }
                    unite(con[j][0],con[j][1]+n*2);
                    unite(con[j][0]+n,con[j][1]);
                    unite(con[j][0]+n*2,con[j][1]+n);
                }
            }
        }
        findwro=n-findwro;
        if(findwro>1)
        {
            printf("Can not determine\n");
        }
        else if(findwro==1)
        {
            int num;
            for(int i=0;i<n;++i)
            {
                if(isjudge[i])
                {
                    num=i;
                    break;
                }
            }
            printf("Player %d can be determined to be the judge after %d lines\n",num,maxjudge);
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}