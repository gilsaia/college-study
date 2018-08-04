#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
bool cmp1(int a,int b)
{
    return a<b;
}
bool cmp2(int a,int b)
{
    return a>b;
}
int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T;
    in>>T;
    int N=1;
    while(T--)
    {
        int n;
        in>>n;
        int n1[810],n2[810];
        for(int i=0;i<n;i++)
        {
            in>>n1[i];
        }
        for(int i=0;i<n;i++)
        {
            in>>n2[i];
        }
        sort(n1,n1+n,cmp1);
        sort(n2,n2+n,cmp2);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long temp=n1[i];
            temp*=n2[i];
            ans+=temp;
        }
        out<<"Case #"<<N<<": "<<ans<<endl;
        N++;
    }
    return 0;
}