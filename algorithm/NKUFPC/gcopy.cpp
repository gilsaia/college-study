#include <bits/stdc++.h>
#define INF 100000500000000000
using namespace std;
typedef long long ll;
int n,m;
int dp1[150000],dp2[150000],t[150000],sum=0;
int times[150000];
bool used[150000];
vector<int> G[150000],rG[150000];
int DP1(int s){//s开始往前找到的最长路径 
	int &ans=dp1[s];
    if(ans>0) return ans;
	ans=t[s];
	for(int i=0;i<G[s].size();i++){
		int from=G[s][i];
		ans=max(ans,DP1(from)+t[s]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[b].push_back(a);
		rG[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		sum=max(sum,DP1(i));
	}
	queue<int> que;
	for(int i=1;i<=n;i++){
		if(rG[i].size()==0){
			dp2[i]=sum;
			que.push(i);
		}
	}
	while(!que.empty()){
		int p=que.front(); que.pop();
		for(int i=0;i<G[p].size();i++){
			int from=G[p][i];
			times[from]++;
			if(times[from]==rG[from].size()) que.push(from);
			if(dp2[from]==0||dp2[from]>dp2[p]-t[p]){
				dp2[from]=dp2[p]-t[p];
			}
		}
	}
	if(sum>604800) printf("gugugu\n");
	else printf("Don't worry!\n");
	printf("%d\n",sum);
	printf("%d",dp2[1]-t[1]);
	for(int i=2;i<=n;i++){
		printf(" %d",dp2[i]-t[i]);
	}
	return 0;
}
