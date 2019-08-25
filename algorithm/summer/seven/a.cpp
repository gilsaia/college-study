#include<cstdio>
#include<algorithm>
using namespace std;
int park[320][320];
int dx[4]={2,-2,0,0};
int dy[4]={0,0,2,-2};
int checkx[4]={1,-1,0,0},checky[4]={0,0,1,-1};
int blankx,blanky;
int intenx,inteny;
int m,n;
int ans[520];
int maxstep;
struct node
{
    int pos,car;
};
bool cmp(node a,node b)
{
    return a.car<b.car;
}
int dfs(int step,int &restr)
{
    if(step>restr)
    {
        return 0;
    }
    if(blankx==intenx&&blanky==inteny)
    {
        return 1;
    }
    node tocmp[4];
    int cmpsiz=0;
    for(int i=0;i<4;++i)
    {
        int tx=blankx+dx[i],ty=blanky+dy[i];
        if(tx<0||tx>=m||ty<0||ty>=n)
        {
            continue;
        }
        if(park[tx][ty]==park[blankx+checkx[i]][blanky+checky[i]]&&park[tx][ty]>0)
        {
            if(step>0&&ans[step-1]==park[tx][ty])
            {
                continue;
            }
            tocmp[cmpsiz].pos=i,tocmp[cmpsiz].car=park[tx][ty];
            ++cmpsiz;
        }
    }
    sort(tocmp,tocmp+cmpsiz,cmp);
    for(int i=0;i<cmpsiz;++i)
    {
        int tx=blankx+dx[tocmp[i].pos],ty=blanky+dy[tocmp[i].pos];
        swap(park[blankx][blanky],park[tx][ty]);
        ans[step]=park[blankx][blanky];
        int tmpx=blankx,tmpy=blanky;
        blankx=tx,blanky=ty;
        if(dfs(step+1,restr))
        {
            return 1;
        }
        swap(park[tmpx][tmpy],park[blankx][blanky]);
        blankx=tmpx,blanky=tmpy;
    }
    maxstep=max(maxstep,step);
    return 0;
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            scanf("%d",&park[i][j]);
            if(park[i][j]==-1)
            {
                blankx=i,blanky=j;
            }
        }
    }
    scanf("%d%d",&intenx,&inteny);
    --intenx,--inteny;
    if((intenx+inteny)%2!=(blankx+blanky)%2)
    {
        printf("impossible\n");
        return 0;
    }
    int find=0,findsiz=0;
    int i=1;
    while(true)
    {
        maxstep=0;
        if(dfs(0,i))
        {
            findsiz=i,find=1;
            break;
        }
        if(maxstep<i)
        {
            break;
        }
        ++i;
    }
    if(find)
    {
        for(int i=0;i<findsiz;++i)
        {
            printf("%d",ans[i]);
            if(i!=findsiz-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    else
    {
        printf("impossible\n");
    }
    return 0;
}