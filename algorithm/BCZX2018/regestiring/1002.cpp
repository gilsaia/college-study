//一直超时·······大概是没有想到正确的算法思路吧····
#include<string>
#include<iostream>
#include<vector>
using namespace std;
vector<int> tofind[30];
int main()
{
    int T;
    cin>>T;
    for(int j=1;j<=T;j++)
    {
        int n,q;
        cin>>n>>q;
        string save;
        cin>>save;
        for(int i=0;i<n;i++)
        {
            tofind[save[i]-'A'].push_back(i);
        }
        int l,r;
        cout<<"Case #"<<j<<":"<<endl;
        for(int i=0;i<q;i++)
        {
            cin>>l>>r;
            l--;
            r--;
            int ans=0,temp=500;
            for(int i=0;i<26;i++)
            {
                int low=0,high=tofind[i].size()-1,mid;
                while(low<=high)
                {
                    mid=low+high/2;
                    if(tofind[i][mid]>=l&&tofind[i][mid]<=r)
                    {
                        break;
                    }
                    else if(tofind[i][mid]<l)
                    {
                        high=mid-1;
                        mid=-1;
                    }
                    else if(tofind[i][mid]>r)
                    {
                        low=mid+1;
                        mid=-1;
                    }
                }
                if(mid==-1)
                {
                    continue;
                }
                else
                {
                    temp=i;
                    break;
                }
            }
            for(int i=0;i<tofind[temp].size();i++)
            {
                if(tofind[temp][i]>r)
                {
                    break;
                }
                else if(tofind[temp][i]>=l)
                {
                    ans++;
                }
            }           
            cout<<ans<<endl;
        }
    }
    return 0;
}