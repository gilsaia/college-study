//这个类型题是真的没想到是这么做的···两个二分解决问题···这道题太晚了不想写全是题解不用看了···
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int maxn = 1e5+5;
int a[maxn];
int n, m;
 
bool test(int val){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += (n-1)-(lower_bound(a+i+1,a+n,a[i]+val)-a)+1;
    }
    if(cnt > m) return 1;
    else return 0;
}
 
int main(){
    while(scanf("%d",&n)!=EOF){
	m = n*(n-1)/4;
	for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
	sort(a,a+n);
    int lb = 0, ub = a[n-1] - a[0] + 1;
    while(ub - lb > 1){
        int mid = (lb+ub)>>1;
        if(test(mid)) lb = mid;
        else ub = mid;
        }
    printf("%d\n", lb);
    }
    return 0;
}