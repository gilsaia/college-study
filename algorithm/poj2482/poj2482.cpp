//扫描线的问题···这个思路倒是不难懂···看题解用线段树更快···但是懒得看了···
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define Max 10010
#define Maxx(a,b) (a)>(b)?(a):(b)
using namespace std;
typedef struct Node{ //坐标结构
	__int64 x,y,value;
}node;
node temp[2*Max]; 
node Input[Max];
__int64 n,W,H;
__int64 ans;
bool cmpx(const node &p,const node &q){ //(x,y)偏序关系，先按x排序，相同时，再按y排序，从小到大,注意要用应用排序，否则TLE
	return (p.x==q.x)?(p.y<q.y):(p.x<q.x);
}
bool cmpy(const node &p,const node &q){ //原理同上
	return (p.y==q.y)?(p.value<q.value):(p.y<q.y);
}
int maxint(int u,int v){ //在最大y之差不超过H时，计算最大权值之和
	int n=v-u; //最大x之差不超过W时点个数
	memcpy(temp,Input+u,sizeof(node)*n); //拷贝给temp
	for(int i=0,j=n;i<n;i++,j++){ //添加n个点，其中y为原始点y +h，权值对应相反数
		temp[j].y=temp[i].y+H;
		temp[j].value=-temp[i].value;
	}
	n*=2; 
	sort(temp,temp+n,cmpy); //排序，先对y从小到大排序，然后按value从小到大排序
	__int64 result=0,d=0;
	for(int i=0;i<n;i++){ //核心操作
		if(d<=0)
			d=temp[i].value;
	    else
			d+=temp[i].value;
		if(d>result)
			result=d;
	}
	return result;
}
int main(){
	while(scanf("%I64d%I64d%I64d",&n,&W,&H)!=EOF){
		int i,j;
		for(i=0;i<n;i++)
			scanf("%I64d%I64d%I64d",&Input[i].x,&Input[i].y,&Input[i].value); //输入点信息
		sort(Input,Input+n,cmpx); //排序
		ans=0; //结果
		for(i=0,j=0;j<n;i++){ // 遍历，获取所有可能的最大x之差小于W的点集合
			while(i>0 && i<n && Input[i].x==Input[i-1].x)
				i++;
			while(j<n && Input[j].x-Input[i].x<W)
				j++;
			ans=Maxx(ans,maxint(i,j)); //取大
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
