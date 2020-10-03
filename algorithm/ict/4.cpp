#include<cstdio>
#include<algorithm>
using namespace std;
// 弹弹乐思路 求栈容量相当于求最长下降子序列 由于保证元素互不相同 实际上不需要考虑等于问题 dp[i]含义为长度为i的下降子序列末尾元素
// 由于设置过程能够保证dp序列为下降序列 可以通过二分方法来加快寻找速度 算法复杂度为O(nlogn)
int dp[10020];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    scanf("%d",&n);
    int item,res=1;
    for(int i=0;i<n;++i){
        scanf("%d",&item);
        int pos=lower_bound(dp+1,dp+res+1,item,cmp)-dp;
        dp[pos]=item;
        res=max(res,pos);
        // for(int j=1;j<=n;++j){
        //     if(dp[j]<item){
        //         dp[j]=item;
        //         res=max(res,j);
        //         break;
        //     }
        // }
    }
    printf("%d\n",res);
    return 0;
}