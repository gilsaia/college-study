#include<iostream>
#include<string>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int D[1050][1050];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
	    memset(D,0,sizeof(D));
    	string A,B;
    	cin>>A>>B;
        int len_A = A.length();
        int len_B = B.length();
        D[0][0]=0;
        for(int i=1;i<=len_A;i++)
        {
            D[0][i]=i;
        }
        for(int i=1;i<=len_B;i++)
        {
            D[i][0]=i;
        }
        for(int i=1;i<=len_B;i++)
        {
            for(int j=1;j<=len_A;j++)
                D[i][j]=min(min(D[i-1][j]+1,D[i][j-1]+1),(A[j-1]==B[i-1]?D[i-1][j-1]:D[i-1][j-1]+1));
        }
        cout<<D[len_B][len_A]<<endl;
    }
}
