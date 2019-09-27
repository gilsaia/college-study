#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=120;
ll B[maxn][maxn];
ll det(int n){
  ll res = 1;
	for (int i=1;i<n;i++){
	  for (int j=i+1;j<n;j++){
		while (B[j][i]){
		  ll t = B[i][i] / B[j][i];
		  for (int k=i;k<n;k++) B[i][k] -= B[j][k] * t;
		  for (int k=i;k<n;k++) swap(B[i][k], B[j][k]);
		  res = -res;
		}
	  }
	  if (B[i][i] == 0) return 0;
	  res = res * B[i][i];
	}
  if(res < 0) res = -res;
  return res;
}
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				B[i][j]=-1;
			}
			B[i][i]=n-1;
		}
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			--u,--v;
			if(B[u][v]!=0)
			{
				B[u][v]=B[v][u]=0;
				--B[u][u],--B[v][v];
			}
		}
		ll ans=det(n);
		printf("%lld\n",ans);
    }
	return 0;
}