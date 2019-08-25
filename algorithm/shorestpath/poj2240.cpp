#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
struct edge{
    int u,v;//两个点 
    double r;    //权值 
    edge(int _u = 0, int _v = 0, double _r=0): u(_u), v(_v),r(_r) {}
};
double dis[maxn];//松弛更新数组
vector<edge>e;//用容器存边 
//如果存在从源点可达的权为负的回路。则 应为无法收敛而导致不能求出最短路径
int bellman_ford(int s,int n)
{
    for(int i=0;i<n;++i)
    {
        dis[i]=1;
    }
    //最多做n-1次 
    for(int i=1;i<n;i++)
    {
        int flag=0;
        for(int j=0; j<int(e.size()); j++)
        {
            if(dis[e[j].v] < dis[e[j].u]* e[j].r)
            {
                dis[e[j].v] = dis[e[j].u] * e[j].r;
                flag=1;
            }
        }
        if(flag==0) return 1;//没有负权回路 
    }
    //有负权回路 
    for(int j=0; j < int(e.size()); j++)
    {
        if(dis[e[j].v] < dis[e[j].u]* e[j].r)
        return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,num=1;
    while(cin>>n,n)
    {
        e.clear();
        map<string,int> country;
        for(int i=0;i<n;++i)
        {
            string tmp;
            cin>>tmp;
            country[tmp]=i;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;++i)
        {
            string a,b;
            double rmp;
            cin>>a>>rmp>>b;
            edge tmp;
            tmp.u=country[a],tmp.v=country[b],tmp.r=rmp;
            e.push_back(tmp);
        }
        int ans=bellman_ford(0,n);
        cout<<"Case "<<num++<<": ";
        if(ans)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}