#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<cstring>
using std::cout;
using std::sort;
using std::map;
using std::vector;
using std::lower_bound;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;
using std::cin;
using std::min;
using std::memset;
const int k=10;
const int warmmax=1e4;
const int isdirty=3;
const int needtowash=3;
const int MAXCLOTH=1e3;
const int INF=1e7;
struct cloth
{
    int group,warm,handsome,index,dirty;
    string name;
    bool operator<(cloth &rhs)
    {
        if(group==rhs.group)
        {
            return index<rhs.index;
        }
        return group<rhs.group;
    }
};
ofstream& operator<<(ofstream &os,cloth &s)
{
    os<<s.name<<" "<<s.index<<" "<<s.group<<" "<<s.warm<<" "<<s.handsome<<" "<<s.dirty;
    return os;
}
ifstream& operator>>(ifstream &is,cloth &s)
{
    is>>s.name>>s.index>>s.group>>s.warm>>s.handsome>>s.dirty;
    return is;
}
struct buff
{
    int clotha,clothb,buff;
};
struct edge
{
    int to,cap,rev;
};
vector<edge> G[MAXCLOTH];
bool used[MAXCLOTH];
void add_edge(int from,int to,int cap)
{
    edge tmp;
    tmp.to=to,tmp.cap=cap,tmp.rev=G[to].size();
    G[from].push_back(tmp);
    tmp.to=from,tmp.cap=0,tmp.rev=G[from].size()-1;
    G[to].push_back(tmp);
}
int dfs(int v,int t,int f)
{
    if(v==t)
    {
        return f;
    }
    used[v]=true;
    for(int i=0;i<G[v].size();++i)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0)
        {
            return flow;
        }
        flow+=f;
    }
}
int findpattern(vector<buff> &nowknow)
{
    for(int i=0;i<nowknow.size();++i)
    {
        if(nowknow[i].buff>0)
        {
            add_edge(0,nowknow[i].clotha*2,INF);
            add_edge(nowknow[i].clotha*2+1,1,INF);
            add_edge(nowknow[i].clotha*2,nowknow[i].clothb*2+1,1);
            add_edge(nowknow[i].clothb*2,nowknow[i].clotha*2+1,1);
            add_edge(0,nowknow[i].clothb*2,INF);
            add_edge(nowknow[i].clothb*2+1,1,INF);
        }
    }
    return max_flow(0,1);
}
void process(int warmlow,int warmhig,string dir)
{
    int dp[k+1][warmmax+1];
    vector<int> valueres[2][warmmax+1];
    vector<int> dirtycloth;
    for(int i=0;i<=k;++i)
    {
        for(int j=0;j<=warmmax;++j)
        {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    int clothnum=0,buffnum=0,dirtynum=0;
    ifstream in(dir);
    in>>clothnum;
    vector<cloth> nowhave;
    vector<buff> nowknow;
    map<int,int> findbuff[MAXCLOTH];
    for(int i=0;i<clothnum;++i)
    {
        cloth tmp;
        in>>tmp;
        if(tmp.dirty>isdirty)
        {
            ++dirtynum;
            dirtycloth.push_back(i);
        }
        nowhave.push_back(tmp);
    }
    sort(nowhave.begin(),nowhave.end());
    in>>buffnum;
    for(int i=0;i<buffnum;++i)
    {
        buff tmp;
        in>>tmp.clotha>>tmp.clothb>>tmp.buff;
        findbuff[tmp.clotha][tmp.clothb]=tmp.buff;
        findbuff[tmp.clothb][tmp.clotha]=tmp.buff;
        nowknow.push_back(tmp);
    }
    int nowgroup=1;
    for(int i=0;i<clothnum;++i)
    {
        nowgroup=nowhave[i].group;
        for(int j=0;j<=warmhig;++j)
        {
            if(dp[nowgroup-1][j]==-1)
            {
                continue;
            }
            int value=nowhave[i].handsome-nowhave[i].dirty;
            for(int t=0;t<valueres[(nowgroup-1)%2][j].size();++t)
            {
                if(findbuff[nowhave[i].index].find(valueres[(nowgroup-1)%2][j][t])!=findbuff[nowhave[i].index].end())
                {
                    value+=findbuff[nowhave[i].index][valueres[(nowgroup-1)%2][j][t]];
                }
            }
            if(dp[nowgroup][j+nowhave[i].warm]<dp[nowgroup-1][j]+value)
            {
                dp[nowgroup][j+nowhave[i].warm]=dp[nowgroup-1][j]+value;
                valueres[nowgroup%2][j+nowhave[i].warm]=valueres[(nowgroup-1)%2][j];
                valueres[nowgroup%2][j+nowhave[i].warm].push_back(nowhave[i].index);
            }
        }
    }
    int outindex=warmlow,outval=-1;
    for(int i=warmlow;i<=warmhig;++i)
    {
        if(dp[nowgroup][i]>outval)
        {
            outindex=i,outval=dp[nowgroup][i];
        }
    }
    cout<<"今天推荐的穿衣方案是："<<endl;
    int findindex=0;
    for(int i=0;i<valueres[nowgroup%2][outindex].size();++i)
    {
        while(nowhave[findindex].index!=valueres[nowgroup%2][outindex][i])
        {
            ++findindex;
        }
        cout<<nowhave[findindex].name<<endl;
    }
    int maxpattern=findpattern(nowknow);
    cout<<"实际最大的可能搭配有"<<maxpattern<<"种"<<endl;
    vector<int> actualwear;
    cout<<"今天的实际穿着是?"<<endl;
    int tmp;
    while(cin>>tmp,tmp)
    {
        actualwear.push_back(tmp);
    }
    sort(actualwear.begin(),actualwear.end());
    findindex=0;
    for(int i=0;i<actualwear.size();++i)
    {
        while(nowhave[findindex].index!=actualwear[i])
        {
            ++findindex;
        }
        ++nowhave[findindex].dirty;
        if(nowhave[findindex].dirty>isdirty)
        {
            ++dirtynum;
            dirtycloth.push_back(findindex);
        }
    }
    if(dirtynum>needtowash)
    {
        cout<<"这边的建议是马上洗衣呢"<<endl;
        cout<<"是否打算洗衣(y/n)"<<endl;
        char tmp;
        cin>>tmp;
        if(tmp=='y'||tmp=='Y')
        {
            for(int i=0;i<dirtycloth.size();++i)
            {
                nowhave[i].dirty=0;
            }
        }
    }
    ofstream out(dir);
    out<<clothnum<<endl;
    for(int i=0;i<nowhave.size();++i)
    {
        out<<nowhave[i]<<endl;
    }
    out<<buffnum<<endl;
    for(int i=0;i<nowknow.size();++i)
    {
        out<<nowknow[i].clotha<<" "<<nowknow[i].clothb<<" "<<nowknow[i].buff<<endl;
    }
}
int main()
{
    cout<<"今天的穿衣范围是"<<endl;
    int warmlow,warmhig;
    cin>>warmlow>>warmhig;
    process(warmlow,warmhig,"cloth.txt");
    return 0;
}