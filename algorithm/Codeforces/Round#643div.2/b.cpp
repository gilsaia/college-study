#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int coun[200010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int tmp;
        for(int i=0;i<n;++i){
            scanf("%d",&coun[i]);
        }
        sort(coun,coun+n);
        int res=0,remai=0,last=0;
        for(int i=0;i<n;++i){
            if(coun[i]!=last){
                if(last!=0){
                    res+=remai/last;
                    remai=remai%last;
                }
                last=coun[i];
            }
            if((n-i+remai)<last){
                break;
            }
            ++remai;
        }
        res+=remai/last;
        printf("%d\n",res);
    }
    return 0;
}