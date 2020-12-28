#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll tocmp[40];
ll res[60];
int main(){
    tocmp[0]=1;
    for(int i=1;i<=32;++i){
        tocmp[i]=tocmp[i-1]*2;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        ll tmp;
        for(int i=0;i<n;++i){
            scanf("%lld",&tmp);
            int pos=0;
            while(tocmp[pos+1]<=tmp){
                ++pos;
            }
            res[i]=tocmp[pos];
        }
        printf("%lld",res[0]);
        for(int i=1;i<n;++i){
            printf(" %lld",res[i]);
        }
        printf("\n");
    }
    return 0;
}