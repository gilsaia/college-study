#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        vector<int> cou[2];
        for(int i=0;i<n*2;++i){
            int tmp;
            scanf("%d",&tmp);
            cou[tmp%2].push_back(i+1);
        }
        int num=0;
        for(int i=0;(i+1)<cou[1].size()&&num<(n-1);i+=2){
            printf("%d %d\n",cou[1][i],cou[1][i+1]);
            ++num;
        }
        for(int i=0;num<(n-1);i+=2){
            printf("%d %d\n",cou[0][i],cou[0][i+1]);
            ++num;
        }
    }
    return 0;
}