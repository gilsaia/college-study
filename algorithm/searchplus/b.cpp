#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int inmap[10];
int hashc[10]={1,1,2,6,24,120,720,5040,40320};
char dir[500010];
int last[500010];
bool vis[500010];
int stabl[10]={1,2,3,4,5,6,7,8,0};
int dx[4]={1,-1,3,-3};
char dis[4]={'r','l','d','u'};
int stnum,ennum;
struct node{
    int f,g,h;
    int map[10];
    int x;
    bool operator<(const node &rhs) const
    {
        return g>rhs.g;
    }
};
int check(int input[10])
{
    int num=0;
    for(int i=0;i<9;++i)
    {
        if(input[i]==0)
        {
            continue;
        }
        for(int j=i+1;j<9;++j)
        {
            if(input[j]==0)
            {
                continue;
            }
            if(input[i]>input[j])
            {
                ++num;
            }
        }
    }
    if(num%2)
    {
        return 0;
    }
    return 1;
}
int kt(int input[10])
{
    int count[10];
    for(int i=0;i<9;++i)
    {
        count[i]=i;
    }
    int ans=0;
    for(int i=0;i<9;++i)
    {
        ans+=count[input[i]]*hashc[8-i];
        int tmp=input[i];
        for(int j=tmp;j<9;++j)
        {
            --count[j];
        }
    }
    return ans;
}
int geth(int input[10])
{
    int ans=0;
    for(int i=0;i<9;++i)
    {
        if(input[i]==0)
        {
            continue;
        }
        int tmp=abs((i+1)-input[i])/3+abs((i+1)-input[i])%3;
        ans+=tmp;
    }
    return ans;
}
void bfs(int input[10])
{
    node start;
    for(int i=0;i<9;++i)
    {
        start.map[i]=input[i];
        if(input[i]==0)
        {
            start.x=i;
        }
    }
    start.g=0;
    // start.h=geth(start.map);
    // start.f=start.h;
    priority_queue<node> que;
    que.push(start);
    while(!que.empty())
    {
        node tmp=que.top();
        que.pop();
        int num=kt(tmp.map);
        for(int i=0;i<4;++i)
        {
            node next=tmp;
            if((tmp.x%3==2&&i==0)||(tmp.x%3==0&&i==1)||(tmp.x>5&&i==2)||(tmp.x<3&&i==3))
            {
                continue;
            }
            int nextx=tmp.x+dx[i];
            swap(next.map[tmp.x],next.map[nextx]);
            next.x=nextx;
            int newkt=kt(next.map);
            if(vis[newkt]==1)
            {
                continue;
            }
            vis[newkt]=true;
            dir[newkt]=dis[i];
            last[newkt]=num;
            ++next.g;
            // next.h=geth(next.map);
            // next.f=next.g+next.h;
            if(stnum==newkt)
            {
                return;
            }
            que.push(next);
        }
    }
}
void show(int num)
{
    if(vis[num]==false)
    {
        cout<<"unsolvable";
        return;
    }
    if(num==ennum)
    {
        return;
    }
    show(last[num]);
    cout<<dir[num];
}
int main()
{
    stnum=kt(stabl);
    for(int i=0;i<9;++i)
    {
        char tmp;
        cin>>tmp;
        if(tmp=='x')
        {
            inmap[i]=0;
        }
        else
        {
            inmap[i]=tmp-'0';
        }
    }
    ennum=kt(inmap);
    // int chec=check(inmap);
    // if(chec==0)
    // {
    //     cout<<"unsolvable"<<endl;
    //     return 0;
    // }
    vis[ennum]=true;
    bfs(inmap);
    show(stnum);
    cout<<endl;
    return 0;
}