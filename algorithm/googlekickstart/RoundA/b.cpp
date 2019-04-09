#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int map[300][300],dis[300][300],used[300][300];
int R,C;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int maxdis=0,maxx=0,maxy=0;
int find(int i,int j)
{
    used[i][j]=1;
    if(dis[i][j]!=10000)
    {
        return dis[i][j];
    }
    if(map[i][j]==1)
    {
        dis[i][j]=0;
        return 0;
    }
    else
    {
        for(int t=0;t<4;++t)
        {
            int nowx=i+dx[t],nowy=j+dy[t];
            if(nowx>=0&&nowx<R&&nowy>=0&&nowy<C)
            {
                if(used[nowx][nowy]==0)
                {
                    dis[i][j]=min(dis[i][j],find(nowx,nowy)+1);
                }
                else
                {
                    dis[i][j]=min(dis[i][j],dis[nowx][nowy]+1);
                } 
            }
        }
    }
    if(dis[i][j]>maxdis)
    {
        maxdis=dis[i][j];
        maxx=i,maxy=j;
    }
    return dis[i][j];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        maxdis=0,maxx=0,maxy=0;
        int maxans=10000;
        scanf("%d%d",&R,&C);
        for(int j=0;j<R;++j)
        {
            for(int t=0;t<C;++t)
            {
                char tmp;
                cin>>tmp;
                if(tmp=='0')
                {
                    map[j][t]=0;
                }
                else
                {
                    map[j][t]=1;
                }
                dis[j][t]=10000;
                used[j][t]=0;
            }
        }
        for(int j=0;j<R;++j)
        {
            for(int t=0;t<C;++t)
            {
                if(used[j][t]==0)
                {
                    find(j,t);
                }
            }
        }
        for(int m=0;m<R;++m)
        {
            for(int n=0;n<C;++n)
            {
                maxdis=0;
                int last=map[m][n];
                map[m][n]=1;
                for(int j=0;j<R;++j)
                {
                    for(int t=0;t<C;++t)
                    {
                        dis[j][t]=10000;
                        used[j][t]=0;
                    }
                }
                for(int j=0;j<R;++j)
                {
                    for(int t=0;t<C;++t)
                    {
                        if(used[j][t]==0)
                        {
                            find(j,t);
                        }
                    }
                }
                maxans=min(maxans,maxdis);
                map[m][n]=last;
            }
        }
        printf("Case #%d: %d\n",i,maxans);
    }
    return 0;
}