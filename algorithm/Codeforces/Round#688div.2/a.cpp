#include<cstdio>
#include<set>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        int tmp;
        int res=0;
        scanf("%d%d",&n,&m);
        set<int> tra;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            tra.insert(tmp);
        }
        for(int i=0;i<m;++i){
            scanf("%d",&tmp);
            if(tra.count(tmp)){
                ++res;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}