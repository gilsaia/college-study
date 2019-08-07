#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <cctype>
#include <time.h>

using namespace std;

const int INF = 1<<30;
const int MAXN = 9*9*4+5;
const int MAXR = 9*9*9+5;
const int MAXNODE = MAXN*MAXR+5;

struct DLX {
// 行编号从1开始，列编号为1~n，结点0是表头结点；结点1~n是各列顶部的虚拟结点
    int n, sz; // 列数，结点总数
    int S[MAXN]; //各列结点数

    int row[MAXNODE], col[MAXNODE]; //各结点行列编号
    int L[MAXNODE], R[MAXNODE], U[MAXNODE], D[MAXNODE]; //十字链表

    int ansd, ans[MAXR]; // 解

    void init(int n)  { //n是列数
        this->n = n;

        //虚拟结点
        for (int i = 0; i <= n; i++) {
            U[i] = i; D[i] = i; L[i] = i-1; R[i] = i+1;
        }
        R[n] = 0; L[0] = n;
        sz = n+1;
        memset(S, 0, sizeof(S));
    }

    void addRow(int r, vector<int> columns) {
        //这一行的第一个结点
        //行没有设头结点，每一行连成一个环形
        int first = sz;
        for (int i = 0; i < columns.size(); i++) {
            int c = columns[i];
            L[sz] = sz-1; R[sz] = sz+1; D[sz] = c; U[sz] = U[c];
            D[U[c]] = sz; U[c] = sz;
            row[sz] = r; col[sz] = c;
            S[c]++; sz++;
        }
        R[sz-1] = first; L[first] = sz-1;
    }

    //顺着链表A，遍历s外的其他元素
    #define FOR(i, A, s) for (int i = A[s]; i != s; i = A[i])

    void remove(int c) { //删除c列
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i]) // 对于每一个c列不为0的所有行
            for (int j = R[i]; j != i; j = R[j]) { //删除这一整行
                U[D[j]] = U[j]; D[U[j]] = D[j]; S[col[j]]--;
            }
    }

    void restore(int c) { //回连c列
        for (int i = U[c]; i != c; i = U[i])
            for (int j = L[i]; j != i; j = L[j]) {
                U[D[j]] = j; D[U[j]] = j; S[col[j]]++;
            }
        L[R[c]] = c; R[L[c]] = c;
    }

    int flag;

    void dfs(int d) { //d为递归深度
        if (R[0] == 0) { //找到解
            ansd = d; //记录解的长度
            flag++;
            return ;
        }

        //找S最小的C列
        int c = R[0]; //第一个未删除的列
        for (int i = R[0]; i != 0; i = R[i]) if (S[i]<S[c]) c = i;
        remove(c); //删除第c列
        for (int i = D[c]; i != c; i = D[i]) { //用结点i所在的行覆盖第c列
            if (!flag) ans[d] = row[i];
            for (int j = R[i]; j != i; j = R[j]) remove(col[j]); //删除节结点i所在行覆盖第c列
            dfs(d+1);
            if (flag>1) return ;
            for (int j = L[i]; j != i; j = L[j]) restore(col[j]); // 恢复
        }
        restore(c); //恢复
    }

    int solve(vector<int> &v) {
        v.clear();
        flag = 0;
        dfs(0);
        for (int i = 0; i < ansd; i++) v.push_back(ans[i]);
        return flag;
    }
};

const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;

inline int encode(int a, int b, int c) { return a*81+b*9+c+1; }
inline void decode(int code, int &a, int &b, int &c) {
    code--;
    c = code%9; code /= 9;
    b = code%9; code /= 9;
    a = code;
}

DLX solver;
int Matrix[22][22];
int belong[9][9];
int cnt;

vector<int> columns;

void test() { int *p = 0; (*p) = 0; }

void dfs(int r, int c, int num) {
    belong[r][c] = cnt;
    int t = Matrix[r][c]>>4;
    int nr, nc;
    for (int i = 0; i < 4; i++) if (!(t&(1<<i))) {
        nr = r+dir[i][0]; nc = c+dir[i][1];
        if (!(0<=nr&&nr<9)||!(0<=nc&&nc<9)||belong[nr][nc]!=-1) continue;
        dfs(nr, nc, num+1);
    }
}

void solve() {
    solver.init(9*9*4);
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            Matrix[r][c] %= 16;
            for (int v = 1; v <= 9; v++) {
                if (Matrix[r][c]!=0 && Matrix[r][c]!=v) continue;
                columns.clear();
                columns.push_back(encode(SLOT, r, c));
                columns.push_back(encode(ROW, r, v-1));
                columns.push_back(encode(COL, c, v-1));
                columns.push_back(encode(SUB, belong[r][c], v-1));
                solver.addRow(encode(r, c, v-1), columns);
            }
        }
    }

    int ans = solver.solve(columns);
    if (ans == 2) { puts("Multiple Solutions"); return; }
    if (ans == 0) { puts("No solution"); return; }
    for (int i = 0; i < columns.size(); i++) {
        int r, c, v;
        decode(columns[i], r, c, v);
        Matrix[r][c] = v+1;
    }
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            printf("%d", Matrix[r][c]);
        }
        puts("");
    }
}

int main() {
    #ifdef Phantom01
        freopen("HDU4069.txt", "r", stdin);
//        freopen("HDU4069.out", "w", stdout);
    #endif //Phantom01

    int T;
    scanf("%d", &T);
    for (int C = 1; C <= T; C++) {
        printf("Case %d:\n", C);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &Matrix[i][j]);

        for (int r = 0; r < 9; r++)
            for (int c = 0; c < 9; c++)
                belong[r][c] = -1;

        cnt = 0;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) if (belong[r][c]==-1){
                dfs(r, c, 1);
                cnt++;
            }
        }
        solve();
    }

    return 0;
}