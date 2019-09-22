// Fast Sequence Operations I
// Rujia Liu
// 输入格式：
// n m     数组范围是a[1]~a[n]，初始化为0。操作有m个
// 1 L R v 表示设a[L]+=v, a[L+1]+v, ..., a[R]+=v
// 2 L R   查询a[L]~a[R]的sum, min和max
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxnode = 1<<19;

int _sum, _min, _max, op, qL, qR, v;

struct IntervalTree {
  int sumv[maxnode], minv[maxnode], maxv[maxnode], addv[maxnode];

  // 维护信息
  void maintain(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    sumv[o] = minv[o] = maxv[o] = 0;
    if(R > L) {
      sumv[o] = sumv[lc] + sumv[rc];
      minv[o] = min(minv[lc], minv[rc]);
      maxv[o] = max(maxv[lc], maxv[rc]);
    }
    if(addv[o]) { minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o] * (R-L+1); }
  }

  void update(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    if(qL <= L && qR >= R) { // 递归边界
      addv[o] += v; // 累加边界的add值
    } else {
      int M = L + (R-L)/2;
      if(qL <= M) update(lc, L, M);
      if(qR > M) update(rc, M+1, R);
    }
    maintain(o, L, R); // 递归结束前重新计算本结点的附加信息
  }

  void query(int o, int L, int R, int add) {
    if(qL <= L && qR >= R) { // 递归边界：用边界区间的附加信息更新答案
      _sum += sumv[o] + add * (R-L+1);
      _min = min(_min, minv[o] + add);
      _max = max(_max, maxv[o] + add);
    } else { // 递归统计，累加参数add
      int M = L + (R-L)/2;
      if(qL <= M) query(o*2, L, M, add + addv[o]);
      if(qR > M) query(o*2+1, M+1, R, add + addv[o]);
    }
  }
};

const int INF = 1000000000;

IntervalTree tree;
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&v);
        qL=i,qR=i;
        tree.update(1,1,n);
    }
    for(int i=0;i<q;++i)
    {
        char op[20];
        scanf("%s",op);
        if(op[0]=='Q')
        {
            scanf("%d%d",&qL,&qR);
            _sum=0;
            tree.query(1,1,n,0);
            printf("%d\n",_sum);
        }
        else
        {
            scanf("%d%d%d",&qL,&qR,&v);
            tree.update(1,1,n);
        }
    }
    return 0;
}