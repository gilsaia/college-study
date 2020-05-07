#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> G[200];
struct block{
    int x,y,z;
    int maxhei;
}blocks[200];
bool checkblock(int i,int j){
    return (blocks[i].x<blocks[j].x)&&(blocks[i].y<blocks[j].y);
}
int findlongest(int t){
    if(blocks[t].maxhei){
        return blocks[t].maxhei;
    }
    int res=blocks[t].z;
    int tmp=0;
    for(int i=0;i<G[t].size();++i){
        tmp=max(tmp,findlongest(G[t][i]));
    }
    blocks[t].maxhei=res+tmp;
    return res+tmp;
}
int main(){
    int n;
    int T=1;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i){
            int x[3];
            scanf("%d%d%d",&x[0],&x[1],&x[2]);
            for(int t=0;t<6;++t){
                G[i*6+t].clear();
                blocks[i*6+t].maxhei=0;
            }
            blocks[i*6].x=x[0],blocks[i*6].y=x[1],blocks[i*6].z=x[2];
            blocks[i*6+1].x=x[0],blocks[i*6+1].y=x[2],blocks[i*6+1].z=x[1];
            blocks[i*6+2].x=x[1],blocks[i*6+2].y=x[2],blocks[i*6+2].z=x[0];
            blocks[i*6+3].x=x[1],blocks[i*6+3].y=x[0],blocks[i*6+3].z=x[2];
            blocks[i*6+4].x=x[2],blocks[i*6+4].y=x[0],blocks[i*6+4].z=x[1];
            blocks[i*6+5].x=x[2],blocks[i*6+5].y=x[1],blocks[i*6+5].z=x[0];
            for(int t=0;t<6;++t){
                for(int j=i*6+t-1;j>=0;--j){
                    if(checkblock(i*6+t,j)){
                        G[j].push_back(i*6+t);
                    }
                    if(checkblock(j,i*6+t)){
                        G[i*6+t].push_back(j);
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n*6;++i){
            res=max(res,findlongest(i));
        }
        printf("Case %d: maximum height = %d\n",T,res);
        ++T;
    }
    return 0;
}