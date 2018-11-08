//计算几何问题，看···倒是看懂了···和写的思路不太一样···
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
 
using namespace std;
 
typedef complex<double> P;
#define M_PI 3.14159265358979323846
#define EPS 4E-13
 
//************************************
// Returns:   将极角转为[0, 2pi)之间
// Parameter: double r
//************************************
double normalize(double r)
{
	while (r < 0.0)
		r += 2 * M_PI;
	while (r >= 2 * M_PI)
		r -= 2 * M_PI;
	return r;
}
 
//************************************
// Returns:   从上到下点落入的第一个圆的下标，
// 点没被覆盖则返回-1
// Parameter: vector<P> & points
// Parameter: vector<double> & rs
//************************************
int hit_test(P p, vector<P> &points, vector<double> &rs)
{
	for (int i = rs.size() - 1; i >= 0; --i)
	if (abs(points[i] - p) < rs[i])
		return i;
	return -1;
}
 
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	while (scanf("%d", &n), n)
	{
		vector<P> points;
		vector<double> rs;
		for (int i = 0; i < n; ++i)
		{
			double x, y, r;
			scanf("%lf%lf%lf", &x, &y, &r);
			points.push_back(P(x, y));
			rs.push_back(r);
		}
		vector<bool> visible(n, false);
		for (int i = 0; i < n; ++i) // 从最下面一个开始处理
		{
			vector<double> rads;	// 与其他圆相交的弧的极角
			rads.push_back(0.0);
			rads.push_back(2.0 * M_PI);
			for (int j = 0; j < n; j++)
			{
				double a = rs[i];
				double b = abs(points[j] - points[i]);
				double c = rs[j];
				if (a + b < c || a + c < b || b + c < a)	// 构不成三角形，两圆不相交
					continue;
				double d = arg(points[j] - points[i]);
				double e = acos((a * a + b * b - c * c) / (2 * a * b));
				rads.push_back(normalize(d + e));	// 用极角表示的圆弧的两个端点
				rads.push_back(normalize(d - e));
			}
			sort(rads.begin(), rads.end());
			for (int j = 0; j < rads.size() - 1; j++)
			{
				double rad = (rads[j + 1] + rads[j]) / 2.0;	// 中点与圆心构成的极角
				for (int k = -1; k <= 1; k += 2)			// 中点在圆弧内外的两个点
				{
					int t = hit_test(P(points[i].real() + (rs[i] + EPS * k) * cos(rad), points[i].imag() + (rs[i] + EPS * k) * sin(rad)), points, rs);
					if (t != -1)
						visible[t] = true;
				}
			}
		}
		printf("%d\n", count(visible.begin(), visible.end(), true));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}
/*#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;
struct point
{
    double x,y,r;
}Con[120];
const double eps=1e-14;
int N;
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    while(scanf("%d",&N),N)
    {
        for(int i=0;i<N;++i)
        {
            scanf("%lf%lf%lf",&Con[i].x,&Con[i].y,&Con[i].r);
        }
        int ans=0;
        for(int i=0;i<N;++i)
        {
            bool pan=0;
            vector<pair<double,int>> find;
            for(int j=i+1;j<N;++j)
            {
                if(dist(Con[i],Con[j])>=(Con[i].r+Con[j].r))
                {
                    continue;
                }
                double d=dist(Con[i],Con[j]);
                double t=d*Con[i].r*Con[j].r/(Con[i].r*Con[i].r+Con[j].r*Con[j].r);
                double d1=t*Con[i].r/Con[j].r;
                point tmp;
                tmp.x=Con[i].x+(Con[j].x-Con[i].x)*d1/d;
                tmp.y=Con[i].y+(Con[j].y-Con[i].y)*d1/d;
                point toadd,theposition;
                theposition.x=Con[j].x-Con[i].x;
                theposition.y=Con[j].y-Con[i].y;
                if(theposition.x==0)
                {
                    toadd.x=1;
                    toadd.y=0;
                }
                else if(theposition.y==0)
                {
                    toadd.y=1;
                    toadd.x=0;
                }
                else
                {
                    toadd.x=1;
                    toadd.y=toadd.x*theposition.x/theposition.y;
                    toadd.y*=-1;
                }
                double dis=sqrt(toadd.x*toadd.x+toadd.y*toadd.y);
                toadd.x=toadd.x*t/dis;
                toadd.y=toadd.y*t/dis;
                point margin;
                margin.x=tmp.x+toadd.x;
                margin.y=tmp.y+toadd.y;
                point position2;
                position2.x=margin.x-Con[i].x;
                position2.y=margin.y-Con[i].y;
                double angal=atan2(position2.y,position2.x);
                find.push_back(make_pair(angal,1));
                margin.x=tmp.x-toadd.x;
                margin.y=tmp.y-toadd.y;
                position2.x=margin.x-Con[i].x;
                position2.y=margin.y-Con[i].y;
                angal=atan2(position2.y,position2.x);
                find.push_back(make_pair(angal,-1));
            }
            if(find.empty())
            {
            }
            else
            {
                int num=0;
                bool pan2=0;
                sort(find.begin(),find.end());
                bool positive=0;
                for(int t=0;t<find.size();++t)
                {
                    if(find[t].second>0)
                    {
                        positive=1;
                        num+=find[t].second;
                    }
                    else if(positive)
                    {
                        num+=find[t].second;
                    }
                }
                for(int t=0;t<find.size();++t)
                {
                    num+=find[t].second;
                    if(num==0)
                    {
                        pan2=1;
                        break;
                    }
                }
                if(pan2==0)
                {
                    pan=1;
                }
            }
            if(pan==0)
            {
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}*/