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
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(B,0,sizeof(B));
        for(int i=0;i<m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            ++B[u][u],++B[v][v],--B[u][v],--B[v][u];
        }
        ll ans=det(n);
        printf("%lld\n",ans);
    }
    return 0;
}