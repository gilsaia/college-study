#include<cstdio>
#include<algorithm>
using namespace std;
int dis[1000020];
void pre(){

}
int main(){
    pre();
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int i=0,sum=0;
        while(sum<n){
            ++i;
            sum+=i;
        }
        if((sum-n)==1){
            ++i;
        }
        printf("%d\n",i);
    }
    return 0;
}