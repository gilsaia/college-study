#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int W[1020],S[1020],length[1020],nextm[1020];
vector<int> G[1020];
bool find_mat(int a,int b){
    return W[a]>W[b]&&S[a]<S[b];
}
int dfs(int x){
    if(length[x]!=-1){
        return length[x]+1;
    }
    length[x]=0;
    for(int i=0;i<G[x].size();++i){
        int tmp=dfs(G[x][i]);
        if(tmp>length[x]){
            length[x]=tmp;
            nextm[x]=G[x][i];
        }
    }
    return length[x]+1;
}
int main(){
    int n=0;
    memset(nextm,-1,sizeof(nextm));
    memset(length,-1,sizeof(length));
    while(~scanf("%d%d",&W[n],&S[n])){
        ++n;
        for(int i=0;i<(n-1);++i){
            if(find_mat(i,n-1)){
                G[n-1].push_back(i);
            }
            if(find_mat(n-1,i)){
                G[i].push_back(n-1);
            }
        }
    }
    int res=-1,ans=0;
    for(int i=0;i<n;++i){
        if(dfs(i)>ans){
            ans=length[i]+1;
            res=i;
        }
    }
    printf("%d\n%d\n",ans,res+1);
    while(nextm[res]!=-1){
        printf("%d\n",nextm[res]+1);
        res=nextm[res];
    }
    return 0;
}