#include<iostream>
using namespace std;
typedef long long ll;
ll bicx[1020],bicy[1020],perx[1020],pery[1020];
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m==0)
        {
            break;
        }
        for(int i=0;i<m;++i)
        {
            char tmp;
            cin>>tmp>>bicx[i];
            cin>>tmp>>bicy[i];
            cin>>tmp;
        }
        for(int i=0;i<n;++i)
        {
            char tmp;
            cin>>tmp>>perx[i];
            cin>>tmp>>pery[i];
            cin>>tmp;
        }
        for(int i=0;i<n;++i)
        {
            ll dis;
            cin>>dis;
            ll cmp=dis*dis;
            ll ans=0;
            for(int j=0;j<m;++j)
            {
                if(((bicx[j]-perx[i])*(bicx[j]-perx[i])+(bicy[j]-pery[i])*(bicy[j]-pery[i]))<=cmp)
                {
                    ++ans;
                }
            }
            cout<<ans;
            if(i!=(n-1))
            {
                cout<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}