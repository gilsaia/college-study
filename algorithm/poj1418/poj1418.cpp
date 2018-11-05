#include<cstdio>
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
}