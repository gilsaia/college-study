#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1020];
struct inter{
    int begin,end,power;
};
inter line[1040];
bool cmp(inter a,inter b){
    if(a.begin==b.begin){
        return a.end<b.end;
    }
    return a.begin<b.begin;
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&line[i].begin,&line[i].end,&line[i].power);
        line[i].end+=k;
    }
    sort(line,line+m,cmp);
    for(int i=0;i<m;++i){
        dp[i]=line[i].power;
        for(int j=0;j<i;++j){
            if(line[j].end<=line[i].begin){
                dp[i]=max(dp[i],dp[j]+line[i].power);
            }
        }
    }
    printf("%d\n",*max_element(dp,dp+m));
    return 0;
}