#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll num[200020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%lld",&num[i]);
        }
        ll res=abs(num[n-1]-num[n-2]),maxres=max(abs(num[1]-num[0]),abs(num[n-1]-num[n-2]));
        for(int i=1;i<(n-1);++i){
            res+=abs(num[i]-num[i-1]);
            maxres=max(abs(num[i]-num[i-1])+abs(num[i+1]-num[i])-abs(num[i+1]-num[i-1]),maxres);
        }
        res-=maxres;
        printf("%lld\n",res);
    }
    return 0;
}