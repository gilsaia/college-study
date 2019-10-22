#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=200+30+10;
const int MAXC=200+5;
const int MAXK=30+5;
const int INF=0x3f3f3f3f;
 
int map[MAX][MAX];
int g[MAXC][MAXK];
int k,c,m;
int mid;
 
void floyd(int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
}
int match[MAXK][MAXC];
int vis[MAXK];
bool dfs(int u)
{
	for(int v=0;v<k;v++)
	{
		if(!vis[v]&&g[u][v]<=mid)
		{
			vis[v]=1;
			if(match[v][0]<m)
			{
				match[v][++match[v][0]]=u;
				return true;
			}
			for(int i=1;i<=m;i++)
			{
				if(dfs(match[v][i]))
				{
					match[v][i]=u;
					return true;
				}
			}
		}
	}
	return false;
}
 
int hungray()
{
	int res=0;
	memset(match,0,sizeof(match));
	for(int i=0;i<c;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) res++;
	}
	return res;
}
 
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d%d%d",&k,&c,&m)!=EOF)
	{
		memset(map,0x3f,sizeof(map));
		for(int i=0;i<k+c;i++)
		{
			for(int j=0;j<k+c;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==0&&i!=j) map[i][j]=INF;
			}
		}
		floyd(k+c);
/*		for(int i=0;i<k+c;i++)
		{
			for(int j=0;j<k+c;j++)
				cout<<map[i][j]<<" ";
			cout<<endl;
		}*/
		memset(g,0x3f,sizeof(g));
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<k;j++)
			{
				g[i][j]=map[k+i][j];
			//		cout<<g[k+i][j]<<" ";
			}
		//	cout<<endl;
		}
		int l=0,r=50000;
		while(l<r)
		{
			mid=(l+r)/2;
			if(hungray()>=c) r=mid;
			else l=mid+1;
		}
		printf("%d\n",r);
	}
	return 0;
}