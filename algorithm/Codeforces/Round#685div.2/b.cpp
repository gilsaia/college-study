#include<cstdio>
using namespace std;
char tmp[120];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,q;
        scanf("%d%d",&n,&q);
        scanf("%s",tmp);
        for(int i=0;i<q;++i){
            int l,r;
            scanf("%d%d",&l,&r);
            bool suc=false;
            for(int j=0;j<(l-1);++j){
                if(tmp[j]==tmp[l-1]){
                    suc=true;
                    break;
                }
            }
            if(!suc){
                for(int j=n-1;j>=r;--j){
                    if(tmp[j]==tmp[r-1]){
                        suc=true;
                        break;
                    }
                }
            }
            if(suc){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}