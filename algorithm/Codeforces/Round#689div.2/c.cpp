#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int dat[100020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int tmp;
        int maxdis=n+1;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            if(tmp!=(i+1)){
                maxdis=i+1;
            }
        }
        double t=1,pro;
        for(int i=0;i<m;++i){
            scanf("%d%lf",&tmp,&pro);
            if(tmp>=maxdis){
                t*=(1-pro);
            }
        }
        double res=1-t;
        if(maxdis==(n+1)){
            res=1;
        }
        printf("%.6lf\n",res);
    }
    return 0;
}