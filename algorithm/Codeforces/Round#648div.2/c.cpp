#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int res[200020],a[200020],b[200020];
int main(){
    int n,tmp;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tmp);
        a[tmp]=i;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&tmp);
        b[tmp]=i;
    }
    for(int i=1;i<=n;++i){
        ++res[(a[i]+n-b[i])%n];
    }
    int ans=0;
    for(int i=0;i<n;++i){
        ans=max(ans,res[i]);
    }
    printf("%d\n",ans);
    return 0;
}