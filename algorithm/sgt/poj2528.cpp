// Fast Sequence Operations II
// Rujia Liu
// 输入格式：
// n m     数组范围是a[1]~a[n]，初始化为0。操作有m个
// 1 L R v 表示设a[L]=a[L+1]=...=a[R] = v。其中v > 0
// 2 L R  查询a[L]~a[R]的sum, min和max
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

const int maxnode = 1<<17;

int _sum, op, qL, qR, v;
set<int> se;
struct IntervalTree {
  int sumv[maxnode], setv[maxnode];

  // 维护信息
  void maintain(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    if(R > L) {
      sumv[o] = sumv[lc] + sumv[rc];
    }
    if(setv[o] >= 0) { sumv[o] = setv[o] * (R-L+1); }
  }

  // 标记传递
  void pushdown(int o) {
    int lc = o*2, rc = o*2+1;
    if(setv[o] >= 0) { //本结点有标记才传递。注意本题中set值非负，所以-1代表没有标记
      setv[lc] = setv[rc] = setv[o];
      setv[o] = -1; // 清除本结点标记
    }
  }

  void update(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    if(qL <= L && qR >= R) { // 标记修改
      setv[o] = v;
    } else {
      pushdown(o);
      int M = L + (R-L)/2;
      if(qL <= M) update(lc, L, M); else maintain(lc, L, M);
      if(qR > M) update(rc, M+1, R); else maintain(rc, M+1, R);
    }
    maintain(o, L, R);
  }

  void query(int o, int L, int R) {
    if(setv[o] >= 0) { // 递归边界1：有set标记
      se.insert(setv[o]);
      return;
    }
    int M = L + (R-L)/2;
    query(o*2, L, M);
    query(o*2+1, M+1, R);
  }
};

const int INF = 1000000000;

IntervalTree tree;
int refl[40040];
int start[20020],en[20020];
int tocnt[10020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(&tree,0,sizeof(tree));
        int n;
        map<int,int> findnum;
        scanf("%d",&n);
        se.clear();
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&start[i],&en[i]);
            refl[i*2]=start[i],refl[i*2+1]=en[i];
        }
        sort(refl,refl+n*2);
        int m=unique(refl,refl+n*2)-refl;
        int t=m;
        for(int i=1;i<t;++i)
        {
            if(refl[i]-refl[i-1]>1)
            {
                refl[m++]=refl[i-1]+1;
            }
        }
        sort(refl,refl+m);
        for(int i=0;i<m;++i)
        {
            findnum[refl[i]]=i+1;
        }
        for(int i=0;i<n;++i)
        {
            qL=findnum[start[i]],qR=findnum[en[i]];
            v=i+1;
            tree.update(1,1,m);
        }
        memset(tocnt,0,sizeof(tocnt));
        qL=1,qR=m;
        tree.query(1,1,m);
        int ans=se.size();
        printf("%d\n",ans);
    }
    return 0;
}