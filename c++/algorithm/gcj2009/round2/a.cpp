#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int M[42][42];
int a[42];
int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T;
    in>>T;
    for(int i=1;i<=T;i++)
    {
        int n;
        in>>n;
        for(int j=0;j<n;j++)
        {
            char k;
            for(int t=0;t<n;t++)
            {
                in>>k;
                if(k=='0')
                {
                    M[j][t]=0;
                }
                else
                {
                    M[j][t]=1;
                }
            }
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {
            a[j]=-1;
            for(int t=0;t<n;t++)
            {
                if(M[j][t]==1)
                {
                    a[j]=t;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            int pos=-1;
            for(int t=j;t<n;t++)
            {
                if(a[t]<=j)
                {
                    pos=t;
                    break;
                }
            }
            for(int t=pos;t>j;t--)
            {
                swap(a[t],a[t-1]);
                ans++;
            }
        }
        out<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}