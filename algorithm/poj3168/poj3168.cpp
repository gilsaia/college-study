//计算几何扫描线问题···就是找交线···倒是不难···
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct line
{
    int height,start,end,num;
};
bool cmp(line a,line b)
{
    if(a.height==b.height)
    {
        if(a.start==b.start)
        {
            return a.end<b.end;
        }
        return a.start<b.start;
    }
    return a.height<b.height;
}
bool can[30000];
void check(vector<line> &s)
{
    int up=s[0].end;
    for(int i=1;i<s.size();++i)
    {
        if(s[i].height==s[i-1].height)
        {
            if(up>=s[i].start)
            {
                can[s[i].num]=can[s[i-1].num]=true;
            }
            up=max(up,s[i].end);
        }
        else
        {
            up=s[i].end;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<line> xpoint,ypoint;
    for(int i=0;i<n;++i)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        line xlow,xhigh,ylow,yhigh;
        xlow.num=i,xlow.height=b,xlow.start=a,xlow.end=c;
        xhigh.num=i,xhigh.height=d,xhigh.start=a,xhigh.end=c;
        ylow.num=i,ylow.height=a,ylow.start=b,ylow.end=d;
        yhigh.num=i,yhigh.height=c,yhigh.start=b,yhigh.end=d;
        xpoint.push_back(xlow);
        xpoint.push_back(xhigh);
        ypoint.push_back(ylow);
        ypoint.push_back(yhigh);
    }
    sort(xpoint.begin(),xpoint.end(),cmp);
    sort(ypoint.begin(),ypoint.end(),cmp);
    check(xpoint);
    check(ypoint);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(can[i]==false)
        {
            ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}