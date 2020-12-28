#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll dp[100020];
int dpnum[100020][2];
char str[100020];
ll x,y;
int main(){
    scanf("%s",str);
    scanf("%lld%lld",&x,&y);
    int curnum[2]={0,0},quesnum=0;
    ll res=0;
    for(int i=0;str[i];++i){
        if(str[i]=='0'){
            res+=y*curnum[1];
            curnum[0]++;
        }else if(str[i]=='1'){
            res+=x*curnum[0];
            curnum[1]++;
        }else{
            dpnum[quesnum][0]=curnum[0];
            dpnum[quesnum][1]=curnum[1];
            quesnum++;
        }
    }
    for(int i=0;i<quesnum;++i){
        for(int j=i+1;j>=0;--j){
            if(j==0){
                dp[j]=dp[j]+y*dpnum[i][1]+x*(curnum[1]-dpnum[i][1]);
            }else{
                dp[j]=min(dp[j]+y*dpnum[i][1]+x*(curnum[1]-dpnum[i][1])+y*j,dp[j-1]+x*dpnum[i][0]+y*(curnum[0]-dpnum[i][0])+x*(i+1-j));
            }
        }
    }
    ll tmp=dp[0];
    for(int i=1;i<quesnum;++i){
        tmp=min(tmp,dp[i]);
    }
    printf("%lld\n",res+tmp);
    return 0;
}