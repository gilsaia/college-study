#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=0x3f3f3f3f;
int dp[1020][2];
struct wal{
    int x[2];
    int h;
    int ans[2];
    int next[2];
};
wal walls[1020];
bool cmp(wal a,wal b){
    return a.h>b.h;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x,y,hmax;
        scanf("%d%d%d%d",&n,&x,&y,&hmax);
        for(int i=1;i<=n;++i){
            scanf("%d%d%d",&walls[i].x[0],&walls[i].x[1],&walls[i].h);
        }
        walls[0].x[0]=walls[0].x[1]=x;
        walls[0].h=y;
        sort(walls+1,walls+1+n,cmp);
        memset(dp,MAXN,sizeof(dp));
        dp[0][0]=dp[0][1]=0;
        int ans=MAXN;
        for(int i=0;i<=n;++i){
            walls[i].ans[0]=walls[i].ans[1]=MAXN;
            walls[i].next[0]=walls[i].next[1]=-1;
            for(int j=0;j<i;++j){
                if((walls[j].h-walls[i].h)>hmax){
                    continue;
                }
                if(dp[j][0]!=MAXN&&walls[j].x[0]>=walls[i].x[0]&&walls[j].x[0]<=walls[i].x[1]&&walls[j].next[0]==-1){
                    walls[j].next[0]=i;
                    dp[i][0]=min(dp[i][0],dp[j][0]+walls[j].h-walls[i].h+abs(walls[j].x[0]-walls[i].x[0]));
                    dp[i][1]=min(dp[i][1],dp[j][0]+walls[j].h-walls[i].h+abs(walls[j].x[0]-walls[i].x[1]));
                }
                if(dp[j][1]!=MAXN&&walls[j].x[1]>=walls[i].x[0]&&walls[j].x[1]<=walls[i].x[1]&&walls[j].next[1]==-1){
                    walls[j].next[1]=i;
                    dp[i][0]=min(dp[i][0],dp[j][1]+walls[j].h-walls[i].h+abs(walls[j].x[1]-walls[i].x[0]));
                    dp[i][1]=min(dp[i][1],dp[j][1]+walls[j].h-walls[i].h+abs(walls[j].x[1]-walls[i].x[1]));
                }
            }
            if(walls[i].h<=hmax){
                walls[i].ans[0]=min(walls[i].ans[0],dp[i][0]+walls[i].h);
                walls[i].ans[1]=min(walls[i].ans[1],dp[i][1]+walls[i].h);
            }
        }
        for(int i=0;i<=n;++i){
            if(walls[i].next[0]==-1){
                ans=min(ans,walls[i].ans[0]);
            }
            if(walls[i].next[1]==-1){
                ans=min(ans,walls[i].ans[1]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}