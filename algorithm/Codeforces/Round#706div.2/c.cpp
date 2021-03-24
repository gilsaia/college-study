#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int miner[100020],diamond[100020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int x,y;
        int indmin=0,inddia=0;
        for(int i=0;i<n*2;++i){
            scanf("%d%d",&x,&y);
            if(x==0){
                diamond[inddia]=abs(y);
                inddia++;
            }else{
                miner[indmin]=abs(x);
                indmin++;
            }
        }
        sort(miner,miner+n);
        sort(diamond,diamond+n);
        double res=0;
        for(int i=0;i<n;++i){
            double x=miner[i],y=diamond[i];
            res+=sqrt(x*x+y*y);
        }
        printf("%.10lf\n",res);
    }
    return 0;
}