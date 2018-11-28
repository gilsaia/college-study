#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
vector<int> canditate[100020];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        canditate[x].push_back(y);
    }
    int maxsize=0;
    for(int i=1;i<=m;++i)
    {
        sort(canditate[i].begin(),canditate[i].end(),cmp);
        maxsize=max(maxsize,(int)canditate[i].size());
    }
    int ans=0;
    for(int i=1;i<=maxsize;++i)
    {
        int anstmp=0;
        for(int j=1;j<=m;++j)
        {
            if(canditate[j].size()>=i)
            {
                int cantmp=0;
                for(int t=0;t<i;++t)
                {
                    cantmp+=canditate[j][t];
                }
                if(cantmp>=0)
                {
                    anstmp+=cantmp;
                }
            }
        }
        ans=max(ans,anstmp);
    }
    printf("%d\n",ans);
    return 0;
}