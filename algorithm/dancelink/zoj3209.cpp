#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1030;
const int MAXM = 1030;
const int INF = 1e9 + 7;
const int maxnode = 1000300;
struct DLX      //矩阵的行和列是从1开始的  
{
	int n, m, size; //size为结点数  
	int U[maxnode], D[maxnode], L[maxnode], R[maxnode], Row[maxnode], Col[maxnode];
	int H[MAXN], S[MAXM];   //H为每一行的头结点，但不参与循环。S为每一列的结点个数  
	int ansd;

	void init(int _n, int _m)   //m为列  
	{
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++)   //初始化列的头结点  
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++) H[i] = -1;    //初始化行的头结点  
	}

	void Link(int r, int c)
	{
		size++; //类似于前向星  
		Col[size] = c;
		Row[size] = r;
		S[Col[size]]++;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] == -1) H[r] = L[size] = R[size] = size; //当前行为空  
		else        //当前行不为空： 头插法，无所谓顺序，因为Row、Col已经记录了位置  
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}

	void remove(int c)  //c是列的编号， 不是结点的编号  
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];     //在列的头结点的循环队列中， 越过列c  
		for (int i = D[c]; i != c; i = D[i])
			for (int j = R[i]; j != i; j = R[j])
			{
				//被删除结点的上下结点仍然有记录  
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				S[Col[j]]--;
			}
	}

	void resume(int c)
	{
		L[R[c]] = R[L[c]] = c;
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j])
			{
				U[D[j]] = D[U[j]] = j;
				S[Col[j]]++;
			}
	}

	void Dance(int d)
	{
		if (d >= ansd) return;
		if (R[0] == 0)
		{
			ansd = d;
			return;
		}

		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])   //挑结点数最少的那一列，否则会超时，那为什么呢?  
			if (S[i] < S[c])
				c = i;

		remove(c);
		for (int i = D[c]; i != c; i = D[i])
		{
			for (int j = R[i]; j != i; j = R[j]) remove(Col[j]);
			Dance(d + 1);
			for (int j = L[i]; j != i; j = L[j]) resume(Col[j]);
		}
		resume(c);
	}
};
DLX dlx;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, p;
		scanf("%d%d%d", &n, &m, &p);
		dlx.init(p, n * m);
		for (int i = 1; i <= p; ++i)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int j = x1 + 1; j <= x2; ++j)
			{
				for (int t = y1 + 1; t <= y2; ++t)
				{
					dlx.Link(i, (j - 1) * m + t);
				}
			}
		}
		dlx.ansd = INF;
		dlx.Dance(0);
		int ans = -1;
		if (dlx.ansd != INF)
		{
			ans = dlx.ansd;
		}
		printf("%d\n", ans);
	}
	return 0;
}