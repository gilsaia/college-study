#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
const int MAXN=1e6;
vector<int> h;//索引
vector<int> l;//路径
bool used[MAXN];//bfs查找用来记录是否遍历过
int *bfsfindpath(int theSource,int theDestination)
{
    vector<int> prev;//路径回溯数组
    prev.resize(h.size());//开到节点个数大小
    prev[theDestination]=-1;//设置一下以确定最后能否找到路径
    queue<pair<int,int>> que;
    int *res,length;
    que.push(make_pair(theSource,0));//放入起点，前一个数据为下一个节点，后一个数据为当前路径长度
    while(!que.empty())//bfs
    {
        pair<int,int> nowcheck=que.front();
        que.pop();
        if(nowcheck.first==theDestination)//当找到终点时
        {
            res=new int[nowcheck.second+1];//返回的结果数组开到能存下路径长度
            length=nowcheck.second;//存下当前路径长度
            break;
        }
        for(int i=h[nowcheck.first];i<h[nowcheck.first+1];++i)//对当前节点路径的遍历（注意索引数组中结尾一定要有哨兵）
        {
            if(!used[l[i]])//如果未遍历过
            {
                pair<int,int> tmp;
                tmp.first=l[i];
                tmp.second=nowcheck.second++;//路径长度加一
                prev[tmp.first]=nowcheck.first;//存下当前边的回溯
                que.push(tmp);
                used[l[i]]=true;//已遍历过
            }
        }
    }
    if(prev[theDestination]==-1)//不存在路径情况··
    {
        //你想咋着咋着
    }
    int prevpoint=theDestination;//从终点向前回溯路径
    while(length--)
    {
        prevpoint=res[length]=prev[prevpoint];//存入结果数组并更新回溯值
    }
    res[length]=theSource;//不要忘了0处应为起点
    return res;
}