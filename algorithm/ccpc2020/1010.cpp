#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int tmp,tmp2;
        scanf("%d",&tmp);
        bool res=true;
        for(int i=1;i<n;++i){
            scanf("%d",&tmp2);
            if(!(tmp^tmp2)){
                res=false;
            }
            tmp=tmp2;
        }
        if(res){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}