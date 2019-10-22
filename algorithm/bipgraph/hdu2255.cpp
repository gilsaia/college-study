#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 310
#define Inf 1000010
int match[Max][Max];
bool visy[Max];
bool visx[Max];
int pre[Max];
int slack[Max];
int lx[Max];
int ly[Max];
int n;
bool find(int x){
	visx[x]=true;
	for(int i=1;i<=n;i++){
		if(visy[i])
			continue;
		int t=lx[x]+ly[i]-match[x][i];
		if(t==0){
			visy[i]=true;
			if(pre[i]==-1 || find(pre[i])){
				pre[i]=x;
				return true;
			}
		}
		else if(t<slack[i])
			slack[i]=t;
	}
	return false;
}
int Km(){
	memset(ly,0,sizeof(ly));
	memset(pre,-1,sizeof(pre));
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1,lx[i]=-Inf;j<=n;j++)
			if(lx[i]<match[i][j])
				lx[i]=match[i][j];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			slack[j]=Inf;
		while(true){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(find(i))
				break;
			int d=Inf;
			for(j=1;j<=n;j++)
				if(!visy[j] && slack[j]<d)
					d=slack[j];
			for(j=1;j<=n;j++)
				if(visx[j])
					lx[j]-=d;
			for(j=1;j<=n;j++)
				if(visy[j])
					ly[j]+=d;
			    else
					slack[j]-=d;
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)
		if(pre[i]!=-1)
			ans+=match[pre[i]][i];
	return ans;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&match[i][j]);
		printf("%d\n",Km());
	}
	return 0;
}