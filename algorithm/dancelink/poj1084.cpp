#include <iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxN=10024;
const int maxL=128;
int L[maxN],R[maxN],U[maxN],D[maxN];
int C[maxN],H[maxN];
int S[maxN],A[maxN],X[maxN];
bool makeup[maxL][maxL];
int cnt,ans;
void build(int r,int c)
{
	for(int i=0;i<=c;++i){
		U[i]=D[i]=i;
		L[i]=i==0?c:i-1;
		R[i]=(i+1)%(c+1);
		C[i]=i;//colum head's id
		S[i]=0;
	}
	for(int i=1;i<=r;++i)
		H[i]=-1;//row head's id;	
	cnt=c;
}
 
void init(int n)
{
	memset(makeup,false,sizeof(makeup));
	int c=1;
	for(int len=1;len<=n;++len)
		for(int i=1;i+len<=n+1;++i)
			for(int j=1;j+len<=n+1;++j){
				for(int k=0;k<len;++k){
					makeup[(i-1)*(2*n+1)+j+k][c]=true;					
					makeup[(i-1+len)*(2*n+1)+j+k][c]=true;
					makeup[i*n+(i-1)*(n+1)+j+k*(2*n+1)][c]=true;
					makeup[i*n+(i-1)*(n+1)+j+k*(2*n+1)+len][c]=true;
				}	
				c++;
			}
}
 
void link(int r,int c)
{
	++cnt;
	C[cnt]=c;
	++S[c];	
	X[cnt]=r;
	D[cnt]=D[c];
	U[D[c]]=cnt;
	D[c]=cnt;
	U[cnt]=c;
	if(H[r]<0)
		H[r]=L[cnt]=R[cnt]=cnt;
	else{
		R[cnt]=R[H[r]];
		L[cnt]=H[r];
		L[R[H[r]]]=cnt;
		R[H[r]]=cnt;
	}
}
 
void remove(int c)
{
	for(int i=D[c];i!=c;i=D[i]){
		L[R[i]]=L[i];
		R[L[i]]=R[i];
	}	
} 
 
void resume(int c)
{
	for(int i=D[c];i!=c;i=D[i]){
		L[R[i]]=i;
		R[L[i]]=i;
	}	
}
 
int get_H()
{
	bool has[maxL];
	memset(has,false,sizeof(has));
	int res=0;
	for(int i=R[0];i!=0;i=R[i])
		if(!has[i]){
			++res;
			for(int j=D[i];j!=i;j=D[j])
				for(int k=R[j];k!=j;k=R[k])
					has[C[k]]=true;
		}	
	return res;
}
 
void dfs(int k)
{
	if(R[0]==0){
		ans=min(ans,k);
		return ;
	}
	else if(k+get_H()>=ans)
		return ;
	int c=R[0];
	for(int t=R[0],maxx=INF;t!=0;t=R[t])
		if(S[t]<maxx)
			maxx=S[t],c=t;					
	for(int i=D[c];i!=c;i=D[i]){
		remove(i);
		for(int j=R[i];j!=i;j=R[j]){
			remove(j);
			--S[C[j]];
		}
		dfs(k+1);
		for(int j=L[i];j!=i;j=L[j]){
			resume(j);
			++S[C[j]];
		}
		resume(i);			
	}		
}
 
int main()
{
	int cases,n,row,col;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);	
		col=0,row=2*n*(n+1);
		for(int i=1;i<=n;++i)
			col+=i*i;
		build(row,col);
		init(n);
		int num;
		scanf("%d",&num);
		bool vis[maxL];//mark square have been destoryed
		memset(vis,false,sizeof(vis));
		while(num--){
			int r;
			scanf("%d",&r);
			for(int j=1;j<=col;++j)
				if(makeup[r][j]&&!vis[j]){
					vis[j]=true;
					R[L[j]]=R[j];
					L[R[j]]=L[j];
				}				
		}
		for(int i=1;i<=row;++i)
			for(int j=1;j<=col;++j)
				if(makeup[i][j]&&!vis[j])
					link(i,j);
		ans=INF;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;	
} 