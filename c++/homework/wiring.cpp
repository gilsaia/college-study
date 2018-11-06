#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<queue>
using std::queue;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
struct point
{
    int x,y,step;
    point():x{0},y{0},step{0}{}
    bool operator==(point &b)
    {
        return (x==b.x)&&(y==b.y);
    }
};
bool functional(istream &in,ostream &out)
{
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int n,m;
    in>>n>>m;
    vector<vector<char>> map;
    vector<vector<point>> path(n,vector<point>(m));
    point start,end;
    start.step=0;
    vector<vector<bool>> used(n,vector<bool>(m,0));
    for(int i=0;i<n;++i)
    {
        vector<char> tmp;
        for(int j=0;j<m;++j)
        {
            char now;
            in>>now;
            tmp.push_back(now);
            if(now=='a')
            {
                start.x=i,start.y=j;
            }
            else if(now=='b')
            {
                end.x=i,end.y=j;
            }
        }
        map.push_back(tmp);
    }
    queue<point> tofind;
    tofind.push(start);
    while(!tofind.empty())
    {
        point now=tofind.front();
        tofind.pop();
        if(now==end)
        {
            break;
        }
        for(int i=0;i<4;++i)
        {
            point tmp=now;
            tmp.x=now.x+dx[i],tmp.y=now.y+dy[i];
            if(tmp.x>=0&&tmp.x<n&&tmp.y>=0&&tmp.y<m&&used[tmp.x][tmp.y]==false)
            {
                path[tmp.x][tmp.y]=now;
                path[tmp.x][tmp.y].step++;
                tmp.step++;
                used[tmp.x][tmp.y]=true;
                tofind.push(tmp);
            }
        }
    }
    if(path[end.x][end.y].step==0)
    {
        out<<"Can't find the path"<<endl;
        return false;
    }
    int prex=end.x,prey=end.y;
    while(prex!=start.x,prey!=start.y)
    {
        prex=path[prex][prey].x,prey=path[prex][prey].y;
        map[prex][prey]=
    }
}