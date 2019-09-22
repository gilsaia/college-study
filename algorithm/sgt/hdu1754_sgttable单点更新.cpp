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

const int INF = 0;
const int maxnode = 1<<20;

int op, qL, qR, p, v;  //qL和qR为全局变量，询问区间[qL,qR];

struct IntervalTree {
  int minv[maxnode];

  void update(int o, int L, int R) {
    int M = L + (R-L)/2;
    if(L == R) minv[o] = v; // 叶结点，直接更新minv
    else {
      // 先递归更新左子树或右子树
      if(p <= M) update(o*2, L, M); else update(o*2+1, M+1, R);
      // 然后计算本结点的minv
      minv[o] = max(minv[o*2], minv[o*2+1]);
    }
  }

  int query(int o, int L, int R) {
    int M = L + (R-L)/2, ans = INF;
    if(qL <= L && R <= qR) return minv[o]; // 当前结点完全包含在查询区间内
    if(qL <= M) ans = max(ans, query(o*2, L, M)); // 往左走
    if(M < qR) ans = max(ans, query(o*2+1, M+1, R)); // 往右走
    return ans;
  }
};
IntervalTree tree;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(&tree,0,sizeof(tree));
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&v);
            p=i;
            tree.update(1,1,n);
        }
        for(int i=0;i<m;++i)
        {
            char op[10];
            scanf("%s",op);
            if(op[0]=='Q')
            {
                scanf("%d%d",&qL,&qR);
                int out=tree.query(1,1,n);
                printf("%d\n",out);
            }
            else
            {
                scanf("%d%d",&p,&v);
                tree.update(1,1,n);
            }
        }
    }
    return 0;
}