#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;

const LL mod = 10007;
const LL MAXN = 1e5 + 5;
LL dp1[MAXN * 6], dp2[MAXN * 6], dp3[MAXN * 6];
LL lazy_mul[MAXN * 6], lazy_add[MAXN * 6];

inline void pushup(LL root) {
    dp1[root] = (dp1[root << 1] + dp1[root << 1 | 1]) % mod;
    dp2[root] = (dp2[root << 1] + dp2[root << 1 | 1]) % mod;
    dp3[root] = (dp3[root << 1] + dp3[root << 1 | 1]) % mod;
}

inline void pushdown(LL root, LL L, LL R) {
    LL mid = (L + R) >> 1;
    if(lazy_mul[root] != 1) {
        LL a = lazy_mul[root] % mod;
        (lazy_mul[root << 1] *= a) %= mod;
        (lazy_mul[root << 1 | 1] *= a) %= mod;
        (lazy_add[root << 1] *= a) %= mod;
        (lazy_add[root << 1 | 1] *= a) %= mod;
        (dp3[root << 1] *= a * a * a) %= mod;
        (dp3[root << 1 | 1] *= a * a * a) %= mod;
        (dp2[root << 1] *= a * a) %= mod;
        (dp2[root << 1 | 1] *= a * a) %= mod;
        (dp1[root << 1] *= a) %= mod;
        (dp1[root << 1 | 1] *= a) %= mod;
        lazy_mul[root] = 1;
    }
    if(lazy_add[root]) {
        LL a = lazy_add[root] % mod;
        (lazy_add[root << 1] += a) %= mod;
        (lazy_add[root << 1 | 1] += a) %= mod;
        (dp3[root << 1] += 3 * a * dp2[root << 1] + 3 * a * a * dp1[root << 1] + a * a * a * (mid - L + 1)) %= mod;
        (dp3[root << 1 | 1] += 3 * a * dp2[root << 1 | 1] + 3 * a * a * dp1[root << 1 | 1] + a * a * a * (R - mid)) %= mod;
        (dp2[root << 1] += 2 * a * dp1[root << 1] + (mid - L + 1) * a * a) %= mod;
        (dp2[root << 1 | 1] += 2 * a * dp1[root << 1 | 1] + (R - mid) * a * a) %= mod;
        (dp1[root << 1] += a * (mid - L + 1)) %= mod;
        (dp1[root << 1 | 1] += a * (R - mid)) %= mod;
        lazy_add[root] = 0;
    }
}

inline void init() {
    for(LL i = 0; i < (MAXN * 5); ++i) {
        dp1[i] = dp2[i] = dp3[i] = 0;
        lazy_add[i] = 0;
        lazy_mul[i] = 1;
    }
}

inline void updata(LL root, LL L, LL R, LL l, LL r, LL b, LL op) {
    if(l <= L && R <= r) {
        LL a, c;
        if(op == 1) {
            a = 1;
            c = b;
            (lazy_add[root] += b) %= mod;
        }
        else if(op == 2) {
            a = b;
            c = 0;
            (lazy_mul[root] *= b) %= mod;
            (lazy_add[root] *= b) %= mod;
        }
        else if(op == 3) {
            a = 0;
            c = b;
            lazy_mul[root] = 0; //注意这一步不是1
            lazy_add[root] = b;
        }
        dp3[root] = (a * a * a * dp3[root] + 3 * a * a * c * dp2[root] + 3 * a * c * c * dp1[root] + c * c * c * (R - L + 1)) % mod;
        dp2[root] = (a * a * dp2[root] + c * c * (R - L + 1) + 2 * a * c * dp1[root]) % mod;
        dp1[root] = (a * dp1[root] + c * (R - L + 1)) % mod;
        return ;
    }
    pushdown(root, L, R);
    LL mid = (L + R) >> 1;
    if(l <= mid) updata(root << 1, L, mid, l, r, b, op);
    if(mid < r) updata(root << 1 | 1, mid + 1, R, l, r, b, op);
    pushup(root);
}

inline LL query(LL root, LL L, LL R, LL l, LL r, LL op) {
    if(l <= L && R <= r) {
        if(op == 1) return dp1[root] % mod;
        if(op == 2) return dp2[root] % mod;
        if(op == 3) return dp3[root] % mod;
    }
    LL ans = 0;
    pushdown(root, L, R);
    LL mid = (L + R) >> 1;
    if(l <= mid) ans = (ans + query(root << 1, L, mid, l, r, op)) % mod;
    if(mid < r) ans = (ans + query(root << 1 | 1, mid + 1, R, l, r, op)) % mod;
    return ans;
}

int main() {
    // freopen("Data.in", "r", stdin);
    // freopen("Data.out", "w", stdout);
    LL n, m;
    while(scanf("%lld %lld", &n, &m) && (n + m)) {
        init();
        while(m--) {
            LL op, x, y, c;
            scanf("%lld %lld %lld %lld", &op, &x, &y, &c);
            if(op == 4) {
                printf("%lld\n", query(1, 1, n, x, y, c) % mod);
            }
            else {
                updata(1, 1, n, x, y, c, op);
            }
        }
    }
    return 0;
}