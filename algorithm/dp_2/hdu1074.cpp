#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
struct subject{
    string classname;
    int endtime,lasttime;
};
subject classes[20];
struct node{
    int nowtime,score,lastindex;
}dp[1<<17];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        char tmp[120];
        for(int i=0;i<n;++i){
            scanf("%s%d%d",tmp,&classes[i].endtime,&classes[i].lasttime);
            classes[i].classname=tmp;
        }
        memset(dp,0,sizeof(dp));
        int s=1<<n;
        for(int i=1;i<s;++i){
            dp[i].score=0x3fffffff;
            for(int j=n-1;j>=0;--j){
                int t=1<<j;
                if(i&t){
                    int addscore=dp[i&(~t)].nowtime+classes[j].lasttime-classes[j].endtime;
                    if(addscore<0){
                        addscore=0;
                    }
                    if(dp[i&(~t)].score+addscore<dp[i].score){
                        dp[i].score=dp[i&(~t)].score+addscore;
                        dp[i].nowtime=dp[i&(~t)].nowtime+classes[j].lasttime;
                        dp[i].lastindex=j;
                    }
                }
            }
        }
        stack<string> order;
        int t=(1<<n)-1;
        printf("%d\n",dp[t].score);
        while(t){
            order.push(classes[dp[t].lastindex].classname);
            t&=(~(1<<dp[t].lastindex));
        }
        while(!order.empty()){
            printf("%s\n",order.top().c_str());
            order.pop();
        }
    }
    return 0;
}