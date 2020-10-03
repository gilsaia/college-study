#include<cstdio>
using namespace std;
// 整数反转思路 按照模10的结果不断累加即可 由于按照数据范围最多只运行9次 复杂度可以看作O(len(n))
int main(){
    long long n;
    scanf("%lld",&n);
    long long res=0;
    while(n){
        res*=10;
        res+=n%10;
        n/=10;
    }
    printf("%lld\n",res);
    return 0;
}