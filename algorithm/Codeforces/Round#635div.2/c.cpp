#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<functional>
using namespace std;
struct edge{
    int from,to,next;
}edges[400020];
int edid=0;
int node[200020];
bool use[200020];
int height[200020];
int children[200020];
void add_edge(int from,int to){
    edges[edid].from=from;
    edges[edid].to=to;
    edges[edid].next=node[from];
    node[from]=edid++;
}
vector<int> ans;
int findchild(int hei,int num){
    height[num]=hei;
    int child=0;
    for(int i=node[num];i!=-1;i=edges[i].next){
        if(!use[edges[i].to]){
            use[edges[i].to]=true;
            child+=findchild(hei+1,edges[i].to);
        }
    }
    ans.push_back(hei-child);
    return child+1;
}
int main(){
    int n,k;
    memset(node,-1,sizeof(node));
    scanf("%d%d",&n,&k);
    for(int i=0;i<(n-1);++i){
        int from,to;
        scanf("%d%d",&from,&to);
        add_edge(from,to);
        add_edge(to,from);
    }
    use[1]=true;
    findchild(0,1);
    sort(ans.begin(),ans.end(),greater<int>());
    long long res=0;
    for(int i=0;i<k;++i){
        res+=ans[i];
    }
    printf("%I64d\n",res);
    return 0;
}