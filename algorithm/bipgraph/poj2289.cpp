
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
bool inline read(int &x){
    x = 0;
    char c = getchar();
    while(c>'9'||c<'0') c = getchar();
    while(c>='0'&&c<='9'){
        x = x*10+c-'0';
        c = getchar();
    }
    if(c=='\n')
        return false;
    return true;
}
const int mx = 1e3+5;
int len[mx],y[mx][mx];
bool vis[mx];
vector<int>g[mx];
int n,m;
bool find(int u,int d){
    for(int j = 0; j < g[u].size(); j++){
        int v = g[u][j];
        if(!vis[v]){
            vis[v] = 1;
            if(len[v]<d){
                y[v][len[v]++] = u;
                return true;
            }
            for(int i = 0; i < len[v]; i++)
                if(find(y[v][i],d)){
                    y[v][i] = u;
                    return true;
                }
        }
    }
    return false;
}
bool MaxMatch(int d){
    memset(len,0,sizeof(len));
    for(int u = 1; u <= n; u++){
        memset(vis,0,sizeof(vis));
        if(!find(u,d))
            return false;
    }
    return true;
}
int main(){
    while(read(n),read(m),n&&m){
        for(int u = 1; u <= n; u++){
            g[u].clear();
            int v;
            while(read(v))
                g[u].push_back(v);
            g[u].push_back(v);
        }
        int l = 1,r = n;
        while(l<r){
            int mid = (l+r)>>1;
            if(MaxMatch(mid)) r = mid;
            else l = mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}