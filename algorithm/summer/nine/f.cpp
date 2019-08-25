#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        vector<int> enmy;
        for(int i=0;i<n;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            enmy.push_back(tmp);
        }
        int ans=0,nowhei=0;
        while(!enmy.empty())
        {
            ++ans;
            nowhei=0;
            vector<int> toshoot;
            for(int i=0;i<enmy.size();++i)
            {
                if(enmy[i]>=nowhei)
                {
                    nowhei=enmy[i];
                }
                else
                {
                    toshoot.push_back(enmy[i]);
                }
            }
            enmy=toshoot;
        }
        printf("%d\n",ans);
    }
    return 0;
}