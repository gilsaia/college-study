#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::queue;
using std::vector;
using std::endl;
int endx,endy;
struct point
{
    int x,y;
    point():x{0},y{0}{}
    bool operator==(point &b)
    {
        return x==b.x&&y==b.y;
    }
    bool operator!=(point &b)
    {
        return !(*this==b);
    }
};
void print(vector<vector<char>> &map,ostream &out,int n,int m)
{
    out<<"condition start"<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            out<<map[i][j]<<" ";
        }
        out<<endl;
    }
    out<<"condition end"<<endl;
}
void mazetravel(vector<vector<char>> &map,ostream &out,int n,int m,int x,int y)
{
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    if(x==0||x==n-1||y==0||y==m-1)
    {
        endx=x,endy=y;
    }
    for(int i=0;i<4;++i)
    {
        int tmpx=x+dx[i],tmpy=y+dy[i];
        if(tmpx>=0&&tmpx<n&&tmpy>=0&&tmpy<m&&map[tmpx][tmpy]=='0')
        {
            map[tmpx][tmpy]='X';
            //print(map,out,n,m);//用于在dfs时显示每一步的走法
            mazetravel(map,out,n,m,tmpx,tmpy);
        }
    }
}
bool functional(ifstream &in,ofstream &out)
{
    int n,m;
    point start;
    in>>n>>m>>start.x>>start.y;
    vector<vector<char>> map;
    for(int i=0;i<n;++i)
    {
        vector<char> line;
        for(int j=0;j<m;++j)
        {
            char tmp;
            in>>tmp;
            line.push_back(tmp);
        }
        map.push_back(line);
    }
    map[start.x][start.y]='X';
    mazetravel(map,out,n,m,start.x,start.y);
    print(map,out,n,m);
    if(start.x==endx&&start.y==endy)
    {
        out<<"No exit!"<<endl;
        return false;
    }
    else
    {
        out<<"The shortest path is"<<endl;
        vector<vector<point>> path(n,vector<point>(m));
        vector<vector<bool>> used(n,vector<bool>(m,0));
        queue<point> que;
        que.push(start);
        used[start.x][start.y]=true;
        int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
        while(!que.empty())
        {
            point tmp=que.front();
            que.pop();
            if(tmp.x==endx&&tmp.y==endy)
            {
                break;
            }
            for(int i=0;i<4;++i)
            {
                point nextstep=tmp;
                nextstep.x+=dx[i],nextstep.y+=dy[i];
                if(nextstep.x>=0&&nextstep.x<n&&nextstep.y>=0&&nextstep.y<m&&map[nextstep.x][nextstep.y]=='X'&&used[nextstep.x][nextstep.y]==false)
                {
                    path[nextstep.x][nextstep.y]=tmp;
                    used[nextstep.x][nextstep.y]=true;
                    que.push(nextstep);
                }
            }
        }
        map[endx][endy]='Y';
        point last;
        last.x=endx,last.y=endy;
        while(last!=start)
        {
            map[last.x][last.y]='Y';
            last=path[last.x][last.y];
        }
        map[last.x][last.y]='Y';
        print(map,out,n,m);
    }
    return true;
}
int main()
{
    ifstream in("G:\\cs\\coding\\c++\\homework\\mazeinput.txt");
    ofstream out("G:\\cs\\coding\\c++\\homework\\mazeoutput.txt");
    functional(in,out);
    return 0;
}