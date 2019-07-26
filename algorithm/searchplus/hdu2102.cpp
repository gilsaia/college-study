#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    int x,y,z,step;
};
int view[2][15][15];
char puzz[2][15][15];
int px,py,pz;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(view,0,sizeof(view));
        int n,m,time;
        cin>>n>>m>>time;
        for(int i=0;i<2;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int t=0;t<m;++t)
                {
                    cin>>puzz[i][j][t];
                    if(puzz[i][j][t]=='P')
                    {
                        px=j,py=t,pz=i;
                    }
                }
            }
        }
        queue<node> que;
        node start;
        start.x=start.y=start.z=0;
        start.step=0;
        view[0][0][0]=1;
        que.push(start);
        int ans=0;
        while(!que.empty())
        {
            node tmp=que.front();
            que.pop();
            if(tmp.step>time)
            {
                continue;
            }
            if(puzz[tmp.z][tmp.x][tmp.y]=='P')
            {
                ans=1;
                break;
            }
            for(int i=0;i<4;++i)
            {
                node next=tmp;
                int tx=tmp.x+dx[i],ty=tmp.y+dy[i];
                if(tx<0||tx>=n||ty<0||ty>=m)
                {
                    continue;
                }
                if(puzz[tmp.z][tx][ty]=='*')
                {
                    continue;
                }
                if(view[tmp.z][tx][ty]==1)
                {
                    continue;
                }
                if(puzz[tmp.z][tx][ty]=='#')
                {
                    if(puzz[(tmp.z+1)%2][tx][ty]=='#'||puzz[(tmp.z+1)%2][tx][ty]=='*')
                    {
                        continue;
                    }
                    view[tmp.z][tx][ty]=1;
                    view[(tmp.z+1)%2][tx][ty]=1;
                    next.z=(next.z+1)%2;
                    next.x=tx,next.y=ty;
                    ++next.step;
                    que.push(next);
                }
                else
                {
                    view[tmp.z][tx][ty]=1;
                    next.x=tx,next.y=ty;
                    ++next.step;
                    que.push(next);
                }
            }
        }
        if(ans)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}