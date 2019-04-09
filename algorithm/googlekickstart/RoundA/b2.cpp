#include<iostream>
#include<algorithm>
using namespace std;
int map[300][300],dis[300][300];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int R,C;
int change(int i,int j,int distance)
{
    dis[i][j]=distance;
    for(int t=0;t<4;++t)
    {
        int nowx=i+dx[t],nowy=j+dy[t];
        if(nowx>=0&&nowx<R&&nowy>=0&&nowy<C)
        {
            if(dis[nowx][nowy]>(distance+1))
            {
                change(nowx,nowy,distance+1);
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        cin>>R>>C;
        for(int j=0;j<R;++j)
        {
            for(int t=0;t<C;++t)
            {
                dis[j][t]=10000;
            }
        }
        for(int j=0;j<R;++j)
        {
            for(int t=0;t<C;++t)
            {
                char tmp;
                cin>>tmp;
                if(tmp=='0')
                {
                }
                else
                {
                    change(j,t,0);
                }
            }
        }
        for(int j=0;j<R;++j)
        {
            for(int t=0;t<C;++t)
            {
                map[j][t]=dis[j][t];
            }
        }
        int dismax=0,ansmin=10000;
        for(int m=0;m<R;++m)
        {
            for(int n=0;n<C;++n)
            {
                dismax=0;
                for(int j=0;j<R;++j)
                {
                    for(int t=0;t<C;++t)
                    {
                        dis[j][t]=map[j][t];
                    }
                }
                change(m,n,0);
                for(int j=0;j<R;++j)
                {
                    for(int t=0;t<C;++t)
                    {
                        dismax=max(dismax,dis[j][t]);
                    }
                }
                ansmin=min(ansmin,dismax);
            }
        }
        cout<<"Case #"<<i<<": "<<ansmin<<endl;
    }
    return 0;
}