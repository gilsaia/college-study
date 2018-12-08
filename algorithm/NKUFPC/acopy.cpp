#include <bits/stdc++.h>
using namespace std;
char s[1000],maze[15][25];
int num[10],status[10][6],res=0;
int main(){
	scanf("%s",s);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++) 
			scanf("%s",maze[j]);
		int cur=0;
		for(int j=0;j<10;j++){
			for(int k=0;k<20;k++){
				if(maze[j][k]=='#') status[i][cur++]=0;
				else if(maze[j][k]=='@') status[i][cur++]=1;
			}
		}
		scanf("%d",&num[i]);
	}
	for(int i=0;i<=(1<<6)-1;i++){
		for(int k=0;k<10;k++){
			int cur=i,flag=0;
			for(int j=0;j<6;j++){
				if(cur%2==status[k][j]) flag++;
				cur>>=1;
			}
			if(flag!=num[k]) break;
			if(k==9) res++;
		}
	}
	printf("%d\n",res);
	return 0;
}
