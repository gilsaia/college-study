// Dynamic RMQ
// Rujia Liu
// 输入格式：
// n m    数组范围是a[1]~a[n]，初始化为0。操作有m个
// 1 p v  表示设a[p]=v
// 2 L R  查询a[L]~a[R]的min
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MIN = 0;
const int maxnode = 1<<19;

int op, qL, qR, p, v;  //qL和qR为全局变量，询问区间[qL,qR];

struct IntervalTree {
  int minv[maxnode],maxv[maxnode];

  void update(int o, int L, int R) {
    int M = L + (R-L)/2;
    if(L == R) 
    {
        minv[o] = v; // 叶结点，直接更新minv
        maxv[o] = v;
    }
    else {
      // 先递归更新左子树或右子树
      if(p <= M) update(o*2, L, M); else update(o*2+1, M+1, R);
      // 然后计算本结点的minv
      minv[o] = min(minv[o*2], minv[o*2+1]);
      maxv[o] = max(maxv[o*2], maxv[o*2+1]);
    }
  }

  int querymin(int o, int L, int R) {
    int M = L + (R-L)/2, ansmin = INF;
    if(qL <= L && R <= qR) return minv[o]; // 当前结点完全包含在查询区间内
    if(qL <= M) ansmin = min(ansmin, querymin(o*2, L, M)); // 往左走
    if(M < qR) ansmin = min(ansmin, querymin(o*2+1, M+1, R)); // 往右走
    return ansmin;
  }
  int querymax(int o, int L, int R) {
    int M = L + (R-L)/2, ansmax = MIN;
    if(qL <= L && R <= qR) return maxv[o]; // 当前结点完全包含在查询区间内
    if(qL <= M) ansmax = max(ansmax, querymax(o*2, L, M)); // 往左走
    if(M < qR) ansmax = max(ansmax, querymax(o*2+1, M+1, R)); // 往右走
    return ansmax;
  }
};
IntervalTree tree;
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&v);
        p=i+1;
        tree.update(1,1,n);
    }
    for(int i=0;i<q;++i)
    {
        scanf("%d%d",&qL,&qR);
        int ans=tree.querymax(1,1,n)-tree.querymin(1,1,n);
        printf("%d\n",ans);
    }
    return 0;
}