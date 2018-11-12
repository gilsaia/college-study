//平面几何的扫描线算法例题···倒是不难懂···
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
using namespace std;
int N;
double x[40020],y[40020],r[40020];
bool inside(int i,int j)
{
    double dx=x[i]-x[j],dy=y[i]-y[j];
    return dx*dx+dy*dy<=r[j]*r[j];
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;++i)
    {
        scanf("%lf%lf%lf",&r[i],&x[i],&y[i]);
    }
    vector<pair<double,int>> events;
    for(int i=0;i<N;++i)
    {
        events.push_back(make_pair(x[i]-r[i],i));
        events.push_back(make_pair(x[i]+r[i],i+N));
    }
    sort(events.begin(),events.end());
    set<pair<double,int>> outers;
    vector<int> res;
    for(int i=0;i<events.size();++i)
    {
        int id=events[i].second%N;
        if(events[i].second<N)
        {
            set<pair<double,int>>::iterator it=outers.lower_bound(make_pair(y[id],id));
            if(it!=outers.end()&&inside(id,it->second))
            {
                continue;
            }
            if(it!=outers.begin()&&inside(id,(--it)->second))
            {
                continue;
            }
            res.push_back(id);
            outers.insert(make_pair(y[id],id));
        }
        else
        {
            outers.erase(make_pair(y[id],id));
        }
    }
    sort(res.begin(),res.end());
    printf("%d\n",res.size());
    for(int i=0;i<res.size();++i)
    {
        printf("%d%c",res[i]+1,i+1==res.size()?'\n':' ');
    }
    return 0;
}