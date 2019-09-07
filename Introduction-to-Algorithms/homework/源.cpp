/*
题目描述
要求用分治算法（O(nlogn)复杂度）实现寻找n个点中最邻近点对,输出最近距离的平方。
其中0<=x<10000,0<=y<10000，（x,y取整数或者小数点后一位）
点数1<n<=30000.

输入
第一行表示点的数目n；
接下来的n行中，每一行依次表示点的x坐标，y坐标。

输出
输出n个点中最邻近点对距离的平方(小数点后两位)

样例输入
8
1 1
2 2
4 4
8 8
2 2.8
5 6
7 9
11 11
样例输出
0.64
*/
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

struct point
{
	double x, y;
};
bool cmp1(point a, point b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool cmp2(point a, point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
double closest_pair(point * a,int n)
{
	if (n ==2)
	{
		double x = pow(a[0].x - a[1].x, 2);
		double y = pow(a[0].y - a[1].y, 2);
		return x + y;
	}
	if (n == 1)
	{
		return (double)1e9;
	}
	if (n % 2 != 0)
	{
		n = n - 1;
	}
	int Lp = n / 2;
	point * left = new point[Lp];
	for (int i = 0; i < Lp; i++)
	{
		left[i] = a[i];
	}
	point * right = new point[n-Lp];
	for (int i = Lp; i < n; i++)
	{
		right[i-Lp] = a[i];
	}
	double o1 = closest_pair(left, Lp);
	double o2 = closest_pair(right, n-Lp);
	double o;
	if (o1 < o2)
		o = o1;
	else
		o = o2;
	double L = a[Lp].x;
	int j = 0;
	point * b = new point[n];
	for (int i = 0; i < n; i++)
	{
		if ((a[i].x <= L + o) && (a[i].x >= L - o))
		{
			b[j] = a[i];
			j++;
		}
	}
	sort(b, b + j, cmp2);
	for (int i = 0; i < j; i++)
	{
		for (int m = 1; m < 12&&(i+m)<j; m++)
		{
			double x = pow(b[i].x - b[i + m].x, 2);
			double y = pow(b[i].y - b[i + m].y, 2);
				if (x + y < o)
					o = x + y;
		}
	}
	return o;
}

int main()
{
	int n;
	cin >> n;
	point * a = new point[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a + n, cmp1);
	double close=closest_pair(a, n);
	cout <<fixed<< setprecision(2) << close << endl;
	return 0;
}