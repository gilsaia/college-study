#include<cstdio>
using namespace std;
// 合法地址思路 利用递归查找的方法 对于每个位置 尝试当前数段大小是否合理 合理则尝试不加点与加点两种 若为单独的0只尝试直接加点 若超出结果则不考虑 最后判断当前结果是否合理
// 递归过程接近于遍历每一种加点组合 复杂度上限在O(n^3)量级 但通过合理剪枝实际复杂度应远小于此
int dfs(char *ip,int pos,int num,int dot){
    int res=0;
    if(ip[pos]){
        num*=10;
        num+=ip[pos]-'0';
        if(!(num==0||num>255)){
            res+=dfs(ip,pos+1,num,dot);
        }
        if(dot<3&&ip[pos+1]&&num<=255){
            res+=dfs(ip,pos+1,0,dot+1);
        }
    }else if(dot==3&&num<=255){
        ++res;
    }
    return res;
}
int main(){
    char ip[24];
    scanf("%s",ip);
    int res=dfs(ip,0,0,0);
    printf("%d\n",res);
    return 0;
}