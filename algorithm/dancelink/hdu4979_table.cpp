#include <cstdio>
#include <cstring>
 
const int MAXN = 8;
const int MAXR = 1000;
const int MAXC = 1000;
const int MAXNODE = MAXR * MAXC;
const int INF = 0x3f3f3f3f;
 
int stateInCol[MAXC], ccnt;
int rcnt;
int bitcnt[1 << MAXN];
int C[MAXN + 1][MAXN + 1];
 
struct DLX
{
    int sz;
    int H[MAXR], S[MAXC];
    int row[MAXNODE], col[MAXNODE];
    int U[MAXNODE], D[MAXNODE], L[MAXNODE], R[MAXNODE];
    int Min;
 
    void Init(int n)
    {
        for (int i = 0; i <= n; ++i)
        {
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        L[0] = n;
        R[n] = 0;
 
        sz = n + 1;
        memset(S, 0, sizeof(S));
        memset(H, -1, sizeof(H));
    }
 
    void Link(const int& r, const int& c)
    {
        row[sz] = r;
        col[sz] = c;
        D[sz] = D[c];
        U[D[c]] = sz;
        D[c] = sz;
        U[sz] = c;
        if (H[r] == -1)
        {
            H[r] = L[sz] = R[sz] = sz;
        }
        else
        {
            R[sz] = R[H[r]];
            L[R[H[r]]] = sz;
            R[H[r]] = sz;
            L[sz] = H[r];
        }
        S[c]++;
        sz++;
    }
 
    void Remove(const int& c)
    {
        for (int i = D[c]; i != c; i = D[i])
        {
            L[R[i]] = L[i];
            R[L[i]] = R[i];
        }
    }
 
    void Restore(const int& c)
    {
        for (int i = U[c]; i != c; i = U[i])
        {
            L[R[i]] = i;
            R[L[i]] = i;
        }
    }
 
    int A()
    {
        int ret = 0;
        bool vis[MAXC];
 
        memset(vis, 0, sizeof(vis));
        for (int i = R[0]; i != 0; i = R[i])
        {
            if (!vis[i])
            {
                vis[i] = true;
                ++ret;
                for (int j = D[i]; j != i; j = D[j])
                {
                    for (int k = R[j]; k != j; k = R[k])
                    {
                        vis[col[k]] = true;
                    }
                }
            }
        }
 
        return ret;
    }
 
    void Dfs(int cur)
    {
        if (cur + A() >= Min) return;
 
        if (R[0] == 0)
        {
            if (cur < Min)
            {
                Min = cur;
            }
            return;
        }
 
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i])
        {
            if (S[i] < S[c])
            {
                c = i;
            }
        }
 
        for (int i = D[c]; i != c; i = D[i])
        {
            Remove(i);
            for (int j = R[i]; j != i; j = R[j])
            {
                Remove(j);
            }
            Dfs(cur + 1);
            for (int j = L[i]; j != i; j = L[j])
            {
                Restore(j);
            }
            Restore(i);
        }
    }
 
    int Solve()
    {
        Min = INF;
        Dfs(0);
        return Min;
    }
 
} dlx;
 
int Bitcnt(int x)
{
    int ret = 0;
 
    while (x)
    {
        ret += (x & 1);
        x >>= 1;
    }
 
    return ret;
}
 
void GetBitcnt()
{
    for (int i = 0; i < (1 << MAXN); ++i)
    {
        bitcnt[i] = Bitcnt(i);
    }
}
 
void GetC()
{
    for (int i = 1; i <= MAXN; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}
 
void Init()
{
    GetBitcnt();
    GetC();
}
 
void Solve(int N, int M, int R)
{
    ccnt = 0;
    for (int i = 1; i < (1 << N); ++i)
    {
        if (bitcnt[i] == R)
        {
            stateInCol[i] = ++ccnt;
        }
    }
 
    dlx.Init(C[N][R]);
 
    rcnt = 0;
    for (int i = 1; i < (1 << N); ++i)
    {
        if (bitcnt[i] == M)
        {
            ++rcnt;
            for (int j = i; j > 0; j = (i & (j - 1)))
            {
                if (bitcnt[j] == R)
                {
                    dlx.Link(rcnt, stateInCol[j]);
                }
            }
        }
    }
 
    printf("%d", dlx.Solve());
}
 
void SaveTable()
{
    puts("{");
    for (int N = 1; N <= MAXN; ++N)
    {
        puts("  {");
        for (int M = 1; M <= N; ++M)
        {
            printf("    {");
            for (int R = 1; R <= M; ++R)
            {
                if (R > 1)
                {
                    printf(", ");
                }
                Solve(N, M, R);
            }
            printf("}");
            if (M == N)
            {
                puts("");
            }
            else
            {
                puts(",");
            }
        }
        printf("  }");
        if (N == MAXN)
        {
            puts("");
        }
        else
        {
            puts(",");
        }
    }
    puts("}");
}
 
int main()
{
    freopen("table.txt", "w", stdout);
 
    Init();
    SaveTable();
 
    return 0;
}