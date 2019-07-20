#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;++i)
    {
        ll N,K,M;
        cin>>N>>K>>M;
        string res;
        cin>>res;
        ll win=0,lose=0;
        for(int j=0;j<res.size();++j)
        {
            if(res[j]=='0')
            {
                ++lose;
            }
            else if(res[j]=='1')
            {
                ++win;
            }
        }
        lose-=K;
        if(lose<0)
        {
            lose=0;
        }
        ll ans=win-lose;
        if(ans<0)
        {
            ans=0;
        }
        unsigned long long rese=ans*M;
        cout<<rese<<endl;
    }
    return 0;
}