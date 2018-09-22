//二分查找问题···疯狂使用stl···
#include<vector>
#include<cstdio>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
    int N,D,tofind;
    scanf("%d%d",&N,&D);
    --D;
    vector<int> rank;
    for(int i=0;i<N;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(i!=D)
        {
            rank.push_back(tmp);
        }
        else
        {
            tofind=tmp;
        }
    }
    int max=0;
    scanf("%d",&max);
    int result=tofind+max;
    int pos=lower_bound(rank.begin(),rank.end(),result,greater<int>())-rank.begin()+1;
    multiset<int> point;
    for(int i=1;i<N;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        point.insert(-tmp);
    }
    int cur=pos-1;
    while(cur<D)
    {
        int tocheck=rank[cur];
        int thesub=result-tocheck;
        auto res=point.lower_bound(-thesub);
        if(res!=point.end())
        {
            //printf("%d ",*res);
            point.erase(res);
        }
        else
        {
            ++pos;
        }
        ++cur;
    }
    printf("%d\n",pos);
    return 0;
}