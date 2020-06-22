#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int gran[200020],su[200020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int tmp;
        memset(gran,0,sizeof(gran));
        memset(su,0,sizeof(su));
        gran[0]=su[0]=1;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            ++gran[tmp];
        }
        int ans=1;
        for(int i=1;i<=n;++i){
            su[i]=su[i-1]+gran[i];
            if(su[i]>i){
                ans=su[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}