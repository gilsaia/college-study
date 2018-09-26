//状压dp问题在字符串方面···
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=16;
const int INF=1e9;
int n,dp[maxn][1<<maxn];
string str[maxn],ans;
int cost[maxn][maxn];
void init()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j&&str[i].find(str[j])!=string::npos)
            {
                str[j]=str[i];
            }
        }
    }
    sort(str,str+n);
    n=unique(str,str+n)-str;
    memset(cost,0,sizeof(cost));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                int len=min(str[i].size(),str[j].size());
                for(int k=0;k<=len;k++)
                {
                    if(str[i].substr(str[i].size()-k)==str[j].substr(0,k))
                    {
                        cost[i][j]=str[i].length()-k;
                    }
                }
            }
        }
    }
}
void dfs(int id, int s)
{
	if(s == 0)   return;
 
	string tmp; int next_id = -1;
	for(int i = 0; i < n; i++) if(i != id && (s >> i & 1)) {
        if(dp[id][s] == dp[i][s & ~(1 << id)] + cost[id][i]) {
            string t = str[i].substr(str[id].length() - cost[id][i], str[i].length());
            if(next_id == -1 || t < tmp) {
                tmp = t;
                next_id = i;
            }
        }
	}
	ans += tmp;
	dfs(next_id, s & ~(1 << id));
}
 
int main()
{
	//freopen("in.txt", "r", stdin);
	int T, kase = 0;
	cin >> T;
    while(T--) {
		cin >> n;
		for(int i = 0; i < n; i++)	cin >> str[i];
 
		if(n > 1) {
			init();
			for(int i = 0; i <= n; i++)	fill(dp[i], dp[i] + (1 << n), INF);
			for(int i = 0; i < n; i++) {
				dp[i][1 << i] = str[i].length();
			}
 
			for(int s = 0; s < 1 << n; s++) {
                for(int j = 0; j < n; j++) if(dp[j][s] != INF && (s >> j & 1)) {
                    for(int i = 0; i < n; i++) if(!(s >> i & 1)) {
                        dp[i][s | 1 << i] = min(dp[i][s | 1<< i], dp[j][s] + cost[i][j]);
                    }
                }
			}
 
 
			int id = 0;
			for(int i = 1; i < n; i++) {
                if(dp[i][(1 << n) - 1] < dp[id][(1 << n) - 1]) {
                    id = i;
                }
			}
 
 
			ans = str[id];
			dfs(id, (1 << n) - 1);
		} else {
			ans = str[0];
		}
 
		cout << "Scenario #" << ++kase << ":" << endl;
		cout << ans << endl;    cout << endl;
    }
    return 0;
}
