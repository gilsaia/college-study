#include<cstdio>
#include<cstring>
using namespace std;
int used[100020],nex[100020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        memset(used,0,sizeof(used));
        memset(nex,0,sizeof(nex));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;++i){
            int tmp;
            scanf("%d",&tmp);
            scanf("%d",&nex[tmp]);
        }
        int res=0;
        for(int i=1;i<=n;++i){
            if(!nex[i]||nex[i]==i||used[i]){
                continue;
            }
            int nepa=nex[i];
            used[i]=1;
            ++res;
            while(nex[nepa]){
                if(used[nepa]){
                    ++res;
                    break;
                }
                used[nepa]=1;
                ++res;
                nepa=nex[nepa];
            }
            if(!nex[nepa]){
                nepa=i;
                while(nex[nepa]){
                    nex[nepa]=0;
                    used[nepa]=0;
                    nepa=nex[nepa];
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}