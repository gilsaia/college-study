#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        int res=n-k+(k/2);
        printf("%d\n",res);
        for(int i=(k+1)/2;i<k;++i){
            printf("%d ",i);
        }
        for(int i=k+1;i<=n;++i){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}