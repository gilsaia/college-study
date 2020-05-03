#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int x,n,m;
        scanf("%d%d%d",&x,&n,&m);
        for(int i=0;i<n;++i){
            if(x<=20){
                break;
            }
            x=x/2+10;
        }
        if(x<=m*10){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}