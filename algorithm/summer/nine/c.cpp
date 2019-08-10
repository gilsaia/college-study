// Fast Sequence Operations II
// Rujia Liu
// 输入格式：
// n m     数组范围是a[1]~a[n]，初始化为0。操作有m个
// 1 L R v 表示设a[L]=a[L+1]=...=a[R] = v。其中v > 0
// 2 L R  查询a[L]~a[R]的sum, min和max
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxnode = 4000040;

int _sum, _min, _max, op, qL, qR, v;

struct IntervalTree {
	int sumv[maxnode], setv[maxnode];

	// 维护信息
	void maintain(int o, int L, int R) {
		int lc = o * 2, rc = o * 2 + 1;
		if (R > L) {
			sumv[o] = sumv[lc] + sumv[rc];
		}
		if (setv[o] >= 0) { sumv[o] = setv[o] * (R - L + 1); }
	}

	// 标记传递
	void pushdown(int o) {
		int lc = o * 2, rc = o * 2 + 1;
		if (setv[o] >= 0) { //本结点有标记才传递。注意本题中set值非负，所以-1代表没有标记
			setv[lc] = setv[rc] = setv[o];
			setv[o] = -1; // 清除本结点标记
		}
	}

	void update(int o, int L, int R) {
		int lc = o * 2, rc = o * 2 + 1;
		if (qL <= L && qR >= R) { // 标记修改
			setv[o] = v;
		}
		else {
			pushdown(o);
			int M = L + (R - L) / 2;
			if (qL <= M) update(lc, L, M); else maintain(lc, L, M);
			if (qR > M) update(rc, M + 1, R); else maintain(rc, M + 1, R);
		}
		maintain(o, L, R);
	}

	void query(int o, int L, int R) {
		if (setv[o] >= 0) { // 递归边界1：有set标记
			_sum += setv[o] * (min(R, qR) - max(L, qL) + 1);
		}
		else if (qL <= L && qR >= R) { // 递归边界2：边界区间
			_sum += sumv[o]; // 此边界区间没有被任何set操作影响
		}
		else { // 递归统计
			int M = L + (R - L) / 2;
			if (qL <= M) query(o * 2, L, M);
			if (qR > M) query(o * 2 + 1, M + 1, R);
		}
	}
};

const int INF = 1000000000;

IntervalTree tree;
char str[1000020];
int main()
{
	scanf("%s", str);
	memset(&tree, 0, sizeof(tree));
	memset(tree.setv, -1, sizeof(tree.setv));
	tree.setv[1] = 0;
	v = 1;
	int n = strlen(str);
	for (int i = 0; i < n; ++i)
	{
		if ((str[i] - '0') == 1)
		{
			qL = i + 1, qR = i + 1;
			tree.update(1, 1, n);
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int op;
		scanf("%d%d%d", &qL, &qR, &op);
		qL = max(1, qL);
		qR = min(n, qR);
		_sum = 0;
		tree.query(1, 1, n);
		if (op == 0)
		{
			v = 0;
			qR -= _sum;
			tree.update(1, 1, n);
			qL = qR + 1;
			qR += _sum;
			if (qL <= qR)
			{
				v = 1;
				tree.update(1, 1, n);
			}

		}
		else
		{
			v = 1;
			_sum = (qR - qL + 1) - _sum;
			qR -= _sum;
			tree.update(1, 1, n);
			qL = qR + 1;
			qR += _sum;
			if (qL <= qR)
			{
				v = 0;
				tree.update(1, 1, n);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		_sum = 0;
		qL = i + 1, qR = i + 1;
		tree.query(1, 1, n);
		str[i] = '0' + _sum;
	}
	printf("%s\n", str);
	return 0;
}