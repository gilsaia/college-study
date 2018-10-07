//状压dp问题···我一开始想的思路不对···实际一个dfs就好了···
 
#include<iostream>
using namespace std;
 
int n;  //城市数
int m;  //道路数
int vist[11];  //记录城市的访问次数,每个城市最多经过3次
int MinCost;  //最小总花费
struct
{
	int a,b,c,p,r;
}road[11];  //每条道路的付费规则
 
void DFS(int a,int fee)   //a:当前所在城市,fee:当前方案的费用
{
	if(a==n && MinCost>fee)
	{
		MinCost=fee;
		return;
	}
 
	for(int i=1;i<=m;i++)  //枚举道路
	{
		if(a==road[i].a && vist[ road[i].b ]<=3)
		{
			int b=road[i].b;
			vist[b]++;
 
			if(vist[ road[i].c ])
				DFS(b,fee+road[i].p);
			else
				DFS(b,fee+road[i].r);
 
			vist[b]--;       //回溯
		}
	}
	return;
}
 
int main(void)
{
	while(cin>>n>>m)
	{
		memset(vist,0,sizeof(vist));
		vist[1]=1;    //从城市1出发，因此预记录到达1次
		MinCost=2000;
 
		for(int i=1;i<=m;i++)
			cin>>road[i].a>>road[i].b>>road[i].c>>road[i].p>>road[i].r;
 
		DFS(1,0);
		if(MinCost==2000)
			cout<<"impossible"<<endl;
		else
			cout<<MinCost<<endl;
	}
	return 0;
}

/*#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int INF=1e9;
int n,m;
struct road
{
    int to,c,p,r;
};
vector<road> roads[12];
int dp[1<<12][12];
struct touse
{
    bool used[12];
    touse()
    {
        for(int i=0;i<n;++i)
        {
            used[i]=0;
        }
    }
};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        --tmp;
        road tte;
        scanf("%d%d%d%d",&tte.to,&tte.c,&tte.p,&tte.r);
        --tte.to;
        --tte.c;
        roads[tmp].push_back(tte);
    }
    for(int i=0;i<1<<n;i++)
    {
        fill(dp[i],dp[i]+12,INF);
    }
    dp[0][0]=0;
    queue<pair<int,int>> dli;
    queue<touse> uset;
    touse ttt;
    ttt.used[0]=1;
    uset.push(ttt);
    dli.push(make_pair(0,0));
    while(!dli.empty())
    {
        pair<int,int> tmp=dli.front();
        touse xxx=uset.front();
        uset.pop();
        dli.pop();
        xxx.used[tmp.second]=1;
        if(tmp.first>>tmp.second&1)
        {
            tmp.first&=0<<tmp.second;
        }
        for(int i=0;i<roads[tmp.second].size();++i)
        {
            if(roads[tmp.second][i].p<roads[tmp.second][i].r)
            {
                int chan=tmp.first;
                if(!xxx.used[roads[tmp.second][i].c])
                {
                    chan|=1<<roads[tmp.second][i].c;
                }
                if((dp[tmp.first][tmp.second]+roads[tmp.second][i].p)<dp[chan][roads[tmp.second][i].to])
                {
                    dp[chan][roads[tmp.second][i].to]=dp[tmp.first][tmp.second]+roads[tmp.second][i].p;
                    dli.push(make_pair(chan,roads[tmp.second][i].to));
                    uset.push(xxx);
                }
            }
            if((dp[tmp.first][tmp.second]+roads[tmp.second][i].r)<dp[tmp.first][roads[tmp.second][i].to])
            {
                dp[tmp.first][roads[tmp.second][i].to]=dp[tmp.first][tmp.second]+roads[tmp.second][i].r;
                dli.push(make_pair(tmp.first,roads[tmp.second][i].to));
                uset.push(xxx);
            }
        }
    }
    if(dp[0][n-1]==INF)
    {
        printf("impossible\n");
    }
    else
    {
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}*/