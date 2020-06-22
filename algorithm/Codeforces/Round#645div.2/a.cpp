#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=n*m/2;
        if((n*m)%2){
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}