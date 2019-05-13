#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[2][2020],k;
int cmp(char a,char b)
{
    if(a==' '&&b==' ')
    {
        return 0;
    }
    else if(a==' '||b==' ')
    {
        return k;
    }
    if(a>b)
    {
        return a-b;
    }
    return b-a;
}
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    cin>>k;
    for(int i=1;i<=a.size();++i)
    {
        dp[0][i]=dp[0][i-1]+k;
    }
    for(int i=1;i<=b.size();++i)
    {
        for(int j=0;j<=a.size();++j)
        {
            if(j==0)
            {
                dp[i%2][0]=dp[(i-1)%2][0]+k;
            }
            else
            {
                dp[i%2][j]=min(dp[(i-1)%2][j-1]+cmp(b[i-1],a[j-1]),min(dp[(i-1)%2][j]+k,dp[i%2][j-1]+k));
            }
        }
    }
    cout<<dp[b.size()%2][a.size()]<<endl;
    return 0;
}