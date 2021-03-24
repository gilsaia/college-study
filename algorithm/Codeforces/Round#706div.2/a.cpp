#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        char tmp[120];
        scanf("%s",tmp);
        if((k*2+1)>n){
            printf("NO\n");
            continue;
        }
        bool res=true;
        for(int i=0;i<k;++i){
            if(tmp[i]!=tmp[n-1-i]){
                res=false;
                break;
            }
        }
        if(res){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}