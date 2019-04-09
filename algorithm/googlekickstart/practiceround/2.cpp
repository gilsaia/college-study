#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        int n;
        cin>>n;
        vector<int> seq;
        for(int j=0;j<n;++j)
        {
            char tmp;
            cin>>tmp;
            int ins=tmp-'0';
            seq.push_back(ins);
        }
        int ans=0,lim=(n+1)/2,last=0;
        for(int j=0;j<n;++j)
        {
            if(j<lim)
            {
                last+=seq[j];
                ans=max(ans,last);
            }
            else
            {
                last=last-seq[j-lim]+seq[j];
                ans=max(ans,last);
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}