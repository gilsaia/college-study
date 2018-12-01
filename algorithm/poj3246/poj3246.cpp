//凸包问题···强行水过去···就逐个试就好···然而poj再一次炸了···
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
#define MAX_N 100000 + 16
 
typedef int type_xy;
typedef struct Point
{
	int id;
	type_xy x, y;
	Point() {}
	Point(type_xy x, type_xy y) : x(x), y(y) {}
	Point operator + (Point p){ return Point(x + p.x, y + p.y); }
	Point operator - (const Point& p){ return Point(x - p.x, y - p.y); }
	Point operator * (type_xy d){ return Point(x*d, y*d); }
	bool operator < (const Point& a) const
	{
		if (x != a.x) return x < a.x;
		else return y < a.y;
	}
	type_xy dot(Point p) { return x*p.x + y*p.y; }
	type_xy det(Point p) { return x*p.y - y*p.x; }
};
 
Point P[MAX_N], Q[MAX_N];
 
// 向量AB 与 AC 的叉积 如果叉积大于0，那么C在向量AB的逆时针方向，叉积小于0则在AB的顺时针方向。如果叉积等于0，则ABC共线。
inline type_xy cross(Point A, Point B, Point C)
{
	return (B - A).det(C - A);
}
 
// AB和AC构成的平行四边形面积
inline type_xy compute_area(Point A, Point B, Point C)
{
	type_xy res = cross(A, B, C);
	if (res < 0)
	{
		return -res;
	}
	return res;
}
 
// 求多边形面积
inline type_xy compute_area(const vector<Point>& ps)
{
	type_xy total = 0;
	for (int i = 2; i < ps.size(); ++i)
	{
		total += compute_area(ps[0], ps[i - 1], ps[i]);
	}
	return total;
}
 
// 求凸包
vector <Point> convex_hull(Point *ps, int N)
{
	sort(ps, ps + N);
	int k = 0;   // 凸包的顶点数
	vector <Point> qs(N * 2);   // 构造中的凸包
	// 构造凸包的下侧
	for (int i = 0; i < N; ++i)
	{
		while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
		qs[k++] = ps[i];
	}
	// 构造凸包的上侧
	for (int i = N - 2, t = k; i >= 0; --i)
	{
		while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}
 

int main(int argc, char *argv[])
{
	int N;
	while (~scanf("%d", &N) && N > 0)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d", &P[i].x, &P[i].y);
			P[i].id = i;
		}
		memcpy(Q, P, N * sizeof(Point));
		vector<Point> ps = convex_hull(P, N);
		type_xy ans = 0x3f3f3f3f;
		for (int i = 0; i < ps.size(); ++i)
		{
			memcpy(P, Q, N * sizeof(Point));
			swap(P[ps[i].id], P[N - 1]);
			ans = min(ans, compute_area(convex_hull(P, N - 1)));
		}
 
		printf("%d.%s\n", ans / 2, ans % 2 == 1 ? "50" : "00");
	}
	return 0;
}