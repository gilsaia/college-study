#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
const int MAX=2e5+5;
 
bool x[MAX]{0};                //sign for search
int pre[MAX];                  //father node
vector<int> nxt[MAX],d[MAX];   //nxt:adjoining nodes of i;d:nodes of distance i
int dis;
 
int main(){
	int n;
	cin>>n;
    //save adjoining nodes
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		nxt[a].push_back(b);
		nxt[b].push_back(a);
	}
    //search and save nodes of each distance
	x[1]=1;
	dis=0;
	d[0].push_back(1);
	while(!d[dis].empty()){
		for(auto a : d[dis])
			for(auto i : nxt[a]) if(!x[i]){
				x[i]=1;
				d[dis+1].push_back(i);
				pre[i]=a;
			}
		dis++;
	}dis--;
    //search terminal nodes by distance
	int cnt=0;
	while(dis>2){
		for(auto a : d[dis]) if(x[a]){
				cnt++;
				x[pre[a]]=0;
				for(auto j : nxt[pre[a]]) x[j]=0;
			}
		dis--;
	}
	cout<<cnt;
	return 0;
}
