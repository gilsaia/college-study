#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
char str[100020];
int main()
{
    int n,ans=0;
    scanf("%d%s",&n,str);
    vector<pair<int,int>> save;
    for(int i=0;i<n;++i)
    {
        if(str[i]=='G')
        {
            int start=i;
            int j=i;
            for(;j<n;++j)
            {
                if(str[j]=='S')
                {
                    break;
                }
            }
            save.push_back(make_pair(i,j-1));
            i=j-1;
        }
    }
    for(int i=0;i<save.size();++i)
    {
        pair<int,int> tmp=save[i];
        ans=max(ans,(tmp.second+1-tmp.first));
        if(save.size()!=1)
        {
            ans=max(ans,(tmp.second+2-tmp.first));
        }
        if(i+1<save.size())
        {
            pair<int,int> topro=save[i+1];
            if((tmp.second+1)==topro.first-1)
            {
                if(save.size()==2)
                {
                    ans=max(ans,topro.second-tmp.first);
                }
                else
                {
                    ans=max(ans,topro.second+1-tmp.first);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}