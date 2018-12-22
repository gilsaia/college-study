#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
using std::istringstream;
using std::ostringstream;
using std::setw;
using std::string;
using std::cin;
using std::cout;
using std::fstream;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;
using std::queue;
using std::priority_queue;
using std::max;
struct font
{
    int time,num;
    font():time(0),num(0){}
    bool operator<(font &rhs)
    {
        return time>rhs.time;
    }
};
bool onedge(int n,int i)
{
    if(i<n||i%n==0||(i+1)%n==0||i>=n*(n-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
class melt
{
    public:
    melt(int size,istream &get=cin,ostream &put=cout):n(size),in(get),out(put),maxtime(0)
    {
        map.resize(n*n);
        par.resize(n*n);
        used.resize(n*n);
        for(int i=0;i<n*n;++i)
        {
            char tmp;
            in>>tmp;
            map[i]+=tmp;
            if(map[i][0]=='_'&&onedge(n,i))
            {
                startx.push_back(i/n);
                starty.push_back(i%n);
            }
            used[i]=0;
        }
        dx[0]=1,dx[1]=-1,dx[2]=0,dx[3]=0;
        dy[0]=0,dy[1]=0,dy[2]=1,dy[3]=-1;
    }
    bool startcondition()
    {
        if(startx.empty())
        {
            return false;
        }
        for(int i=0;i<startx.size();++i)
        {
            map[startx[i]*n+starty[i]]='0';
            used[startx[i]*n+starty[i]]=-1;
            fond(startx[i],starty[i],0);
        }
        return true;
    }
    void solve()
    {
        out<<"The start condition is:"<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                out<<setw(3)<<map[i*n+j];
            }
            out<<endl;
        }
        out<<"Start condition end"<<endl;
        if(!startcondition())
        {
            out<<"There is no black!"<<endl;
            return;
        }
        while(!tomelt.empty())
        {
            font tmp=tomelt.front();
            tomelt.pop();
            ostringstream outnum;
            outnum<<tmp.time;
            map[tmp.num]=outnum.str();
            maxtime=max(maxtime,tmp.time);
            fond(tmp.num/n,tmp.num%n,tmp.time);
        }
        out<<"The time to use is "<<maxtime<<endl<<"The end condition is"<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                out<<setw(3)<<map[i*n+j];
            }
            out<<endl;
        }
    }
    private:
    ostream &out;
    istream &in;
    vector<string> map;
    vector<int> par,used,startx,starty;
    queue<font> tomelt;
    void fond(int x,int y,int nowtime)
    { 
        for(int i=0;i<4;++i)
        {
            int tx=x+dx[i],ty=y+dy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<n)
            {
                if(map[tx*n+ty][0]=='_'&&used[tx*n+ty]!=-1)
                {
                    ostringstream outnum;
                    outnum<<nowtime;
                    map[tx*n+ty]=outnum.str();
                    used[tx*n+ty]=-1;
                    fond(tx,ty,nowtime);
                }
                else if(map[tx*n+ty][0]=='#')
                {
                    if(++used[tx*n+ty]==2)
                    {
                        font tmp;
                        tmp.num=tx*n+ty;
                        tmp.time=nowtime+1;
                        tomelt.push(tmp);
                    }
                    
                }
            }
        }
    }
    int n,dx[4],dy[4],maxtime;
};
int main()
{
    ifstream in("G:\\cs\\coding\\c++\\homework\\meltinput.txt");
    ofstream out("G:\\cs\\coding\\c++\\homework\\meltoutput.txt");
    int n;
    in>>n;
    melt res(n,in,out);
    res.solve();
    return 0;
}