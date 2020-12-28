#include<cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if((a+b+c)<9){
            printf("NO\n");
            continue;
        }
        if((a+b+c-9)%9){
            printf("NO\n");
            continue;
        }
        int time=(a+b+c-9)/9+1;
        if(a>=time&&b>=time&&c>=time){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}