#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct people{
    int score[2],sum,sub;
}person[230];
int dp[22][820],last[22][820];
void input(int i){
    scanf("%d%d",&person[i].score[0],&person[i].score[1]);
    person[i].sub=person[i].score[0]-person[i].score[1];
    person[i].sum=person[i].score[0]+person[i].score[1];
}
bool select(int j,int t,int i){
    while(last[j][t]!=-1){
        if(last[j][t]==i){
            return false;
        }
        t-=person[last[j][t]].sub;
        j--;
    }
    return true;
}
int main(){
    int n,m;
    int T=1;
    while(scanf("%d%d",&n,&m),n+m){
        memset(dp,-1,sizeof(dp));
        memset(last,-1,sizeof(last));
        dp[0][400]=0;
        for(int i=0;i<n;++i){
            input(i);
        }
        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                for(int t=0;t<=800;++t){
                    if(dp[j][t]!=-1&&select(j,t,i)){
                        if((dp[j][t]+person[i].sum)>dp[j+1][t+person[i].sub]){
                            dp[j+1][t+person[i].sub]=dp[j][t]+person[i].sum;
                            last[j+1][t+person[i].sub]=i;
                        }
                    }
                }
            }
        }
        int ansmax=0,res[2]={0,0},ans;
        bool find=false;
        for(int i=0;i<=400;++i){
            if(dp[m][400+i]!=-1){
                ansmax=dp[m][400+i],ans=400+i;
                find=true;
            }
            if(dp[m][400-i]!=-1){
                if(dp[m][400-i]>ansmax){
                    ansmax=dp[m][400-i],ans=400-i;
                    find=true;
                }
            }
            if(find){
                break;
            }
        }
        int index=m;
        vector<int> resque;
        while(last[index][ans]!=-1){
            int i=last[index][ans];
            resque.push_back(i);
            res[0]+=person[i].score[0],res[1]+=person[i].score[1];
            index--,ans-=person[i].sub;
        }
        sort(resque.begin(),resque.end());
        printf("Jury #%d\n",T);
        T++;
        printf("Best jury has value %d for prosecution and value %d for defence:\n",res[0],res[1]);
        for(int i=0;i<resque.size();++i){
            printf(" %d",resque[i]+1);
        }
        printf("\n\n");
    }
    return 0;
}