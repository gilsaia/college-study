#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=1e5+1;
int isprime[maxn];
vector<int> prime;
void findprime()
{
    for(int i=2;i<maxn;++i)
    {
        if(isprime[i])
        {
            continue;
        }
        int tmp=i*2;
        for(;tmp<maxn;tmp+=i)
        {
            isprime[tmp]=true;
        }
    }
    for(int i=2;i<maxn;++i)
    {
        if(!isprime[i])
        {
            prime.push_back(i);
        }
    }
}
multimap<int,int> prsub[10020];
vector<int> sub[maxn];
int main()
{
    findprime();
    int ans=prime.size();
    int n,k;
    scanf("%d%d",&n,&k);
    int onesiz=0;
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1)
        {
            ++onesiz;
        }
        for(int j=0;j<prime.size();++j)
        {
            int count=0;
            if(prime[j]>tmp)
            {
                break;
            }
            while(tmp%prime[j]==0)
            {
                ++count;
                tmp/=prime[j];
            }
            count%=k;
            sub[i].push_back(j);
            prsub[j][count]=i;
        }
        vector<int> findlist;

    }
    return 0;
}