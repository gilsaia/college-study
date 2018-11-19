#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
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
    melt(int size,istream &get=cin,ostream &put=cout):n(size),in(get),out(put),startx(-1),starty(-1),maxtime(0)
    {
        map.resize(n*n);
        par.resize(n*n);
        used.resize(n*n);
        for(int i=0;i<n*n;++i)
        {
            in>>map[i];
            if(startx==-1&&map[i]=='_'&&onedge(n,i))
            {
                startx=i/n;
                starty=i%n;
            }
            used[i]=0;
        }
        dx[0]=1,dx[1]=-1,dx[2]=0,dx[3]=0;
        dy[0]=0,dy[1]=0,dy[2]=1,dy[3]=-1;
    }
    bool startcondition()
    {
        if(startx==-1&&starty==-1)
        {
            return false;
        }
        map[startx*n+starty]='0';
        used[startx*n+starty]=-1;
        fond(startx,starty,0);
        return true;
    }
    void solve()
    {
        out<<"The start condition is:"<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                out<<map[i*n+j];
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
            map[tmp.num]='0'+tmp.time;
            maxtime=max(maxtime,tmp.time);
            fond(tmp.num/n,tmp.num%n,tmp.time);
        }
        out<<"The time to use is "<<maxtime<<endl<<"The end condition is"<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                out<<map[i*n+j];
            }
            out<<endl;
        }
    }
    private:
    ostream &out;
    istream &in;
    vector<char> map;
    vector<int> par,used;
    queue<font> tomelt;
    void fond(int x,int y,int nowtime)
    { 
        for(int i=0;i<4;++i)
        {
            int tx=x+dx[i],ty=y+dy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<n)
            {
                if(map[tx*n+ty]=='_'&&used[tx*n+ty]!=-1)
                {
                    map[tx*n+ty]='0'+nowtime;
                    used[tx*n+ty]=-1;
                    fond(tx,ty,nowtime);
                }
                else if(map[tx*n+ty]=='#')
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
    int n,startx,starty,dx[4],dy[4],maxtime;
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