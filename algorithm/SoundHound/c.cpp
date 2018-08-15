#include<iostream>
using namespace std;
int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    if(d==0)
    {
        double a=(n-d);
        double b=a/n;
        b*=(m-1);
        double ans=b/n;
        cout.setf(ios::fixed);
        cout.precision(10);
        cout<<ans<<endl;
        return 0;
    }
    else
    {
        double a=(n-d);
        double b=a/n;
        b*=(m-1);
        double ans=b/n;
        ans*=2;
        cout.setf(ios::fixed);
        cout.precision(10);
        cout<<ans<<endl;
        return 0;
    }
}