#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<queue>
#include<string>
#include<sstream>
#include<iomanip>
using std::string;
using std::queue;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ostringstream;
using std::istringstream;
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
bool functional(istream &in,ostream &out)//开头输入行数和列数，然后输入地图即可
{
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int n,m;
    in>>n>>m;
    vector<vector<string>> map;
    vector<vector<point>> path(n,vector<point>(m));
    point start,end;
    start.step=0;
    vector<vector<bool>> used(n,vector<bool>(m,0));
    for(int i=0;i<n;++i)
    {
        vector<string> tmp;
        for(int j=0;j<m;++j)
        {
            string now;
            in>>now;
            tmp.push_back(now);
            if(now[0]=='a')
            {
                start.x=i,start.y=j;
            }
            else if(now[0]=='b')
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
            if(tmp.x>=0&&tmp.x<n&&tmp.y>=0&&tmp.y<m&&used[tmp.x][tmp.y]==false&&map[tmp.x][tmp.y][0]!='X')
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
    while(1)
    {
        point last=path[prex][prey];
        prex=last.x,prey=last.y;
        if(prex==start.x&&prey==start.y)
        {
            break;
        }
        ostringstream strtmp;
        strtmp<<path[prex][prey].step;
        string tmp=strtmp.str();
        map[prex][prey]=tmp;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            out<<setw(3)<<map[i][j]<<" ";
        }
        out<<endl;
    }
    return true;
}
int main()
{
    ifstream in("G:\\cs\\coding\\c++\\homework\\wiringinput.txt");
    ofstream out("G:\\cs\\coding\\c++\\homework\\wiringoutput.txt");
    functional(in,out);
    return 0;
}