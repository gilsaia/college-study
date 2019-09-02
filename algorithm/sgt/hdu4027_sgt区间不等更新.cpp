#include <cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define lc p<<1,s,mid
#define rc p<<1|1,mid+1,e
#define mid ((s+e)>>1)
using namespace std;
typedef long long LL;
const int N = 100005;
LL sum[N * 4];
 
void pushup(int p)
{
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}
 
void build(int p, int s, int e)
{
    if(s == e)
    {
        scanf("%lld", &sum[p]);
        return;
    }
    build(lc);
    build(rc);
    pushup(p);
}
 
void update(int p, int s, int e, int l, int r)
{
    if(sum[p] == e - s + 1) return;  //[e,s]区间所有数都为1
    if(s == e)
    {
        sum[p] = sqrt(sum[p]);
        return;
    }
    if(l <= mid) update(lc, l, r);
    if(r > mid) update(rc, l, r);
    pushup(p);
}
 
LL query(int p, int s, int e, int l, int r)
{
    if(s == l && e == r) return sum[p];
    if(r <= mid) return query(lc, l, r);
    if(l > mid) return query(rc, l, r);
    return query(lc, l, mid) + query(rc, mid + 1, r);
}
 
int main()
{
    int n, m, a, b, c, k = 0;
    while(~scanf("%d", &n))
    {
        printf("Case #%d:\n", ++k);
        build(1, 1, n);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d%d%d", &c, &a, &b);
            if(b < a) swap(a, b);
            if(c) printf("%lld\n", query(1, 1, n, a, b));
            else update(1, 1, n, a, b);
        }
        puts("");
    }
    return 0;
}