//开关问题···但是自己写的不知道哪里有问题啊哭···找的题解发现要从两边分别求完找最小
#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
const int maxn = 25;
 
int a[maxn], f1[maxn], f2[maxn];
 
int main()
{
	//freopen("in.txt", "r", stdin);
	while(~scanf("%d", &a[0])){
		memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
 
		for(int i = 1; i < 20; i++)	scanf("%d", &a[i]);
 
		int sum1 = 0, res1 = 0;
		for(int i = 0; i < 20; i++){	//从左
			if((sum1 + a[i]) & 1){
				res1++;
				f1[i] = 1;
				if(i == 19){
					res1 = 30;
					break;
				}
			}
			sum1 += f1[i];
			if(i - 2 >= 0)	sum1 -= f1[i-2];
		}
 
		int sum2 = 0, res2 = 0;
		for(int i = 19; i >= 0; i--){	//从右
			if((sum2 + a[i]) & 1){
				res2++;
				f2[i] = 1;
				if(i == 0){
					res2 = 30;
					break;
				}
			}
			sum2 += f2[i];
			if(i + 2 < 20)	sum2 -= f2[i+2];
		}
		printf("%d\n", min(res1, res2));
	}
    return 0;
}
