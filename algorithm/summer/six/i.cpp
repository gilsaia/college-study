#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=1e6+5;
struct node
{
    int x;
    int be;
    int en;
}a[MAXN];
double dp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
      scanf("%d%d%d",&a[i].x,&a[i].be,&a[i].en);
    for(int i=n-1;i>=0;i--){
        int fir=a[i].x+a[i].be;
        int las=a[i].x+a[i].en;
        int j=n-1,com;
        double maxx=0;
        dp[i]++;
        int len=las-fir+1; 
        while(las>=fir){   
            while(j>i){
                if(a[j].x<las)
                    break;
                maxx=max(maxx,dp[j]);  
                j--;
            }
            com=max(fir,a[j].x+1);
            dp[i]+=1.0*maxx*(las-com+1)/len;   
            las=com-1;
        }
    }
    double sum=0;
    for (int i=0;i<n;i++)
        sum=max(sum,dp[i]);
    printf("%lf\n",sum);
    return 0;
 
}