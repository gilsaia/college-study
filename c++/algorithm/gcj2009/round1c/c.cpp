//只能是照着书的思路来解了·····只能说勉强看懂了题解···下一题甚至根本看不懂···
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T;
    in>>T;
    for(int p=1;p<=T;p++)
    {
        int P,Q;
        in>>P>>Q;
        int A[120];
        for(int i=1;i<=Q;i++)
        {
            in>>A[i];
        }
        A[0]=0;
        A[Q+1]=P+1;
        int dp[120][120];
        for(int q=0;q<=Q;q++)
        {
            dp[q][q+1]=0;
        }
        for(int w=2;w<=Q+1;w++)
        {
            for(int i=0;i+w<=Q+1;i++)
            {
                int j=i+w,t=1e9;
                for(int k=i+1;k<j;k++)
                {
                    t=min(t,dp[i][k]+dp[k][j]);
                }
                dp[i][j]=t+A[j]-A[i]-2;
            }
        }
        out<<"Case #"<<p<<": "<<dp[0][Q+1]<<endl;
    }
    return 0;
}