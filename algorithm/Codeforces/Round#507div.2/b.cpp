#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int n,k,cov;
    scanf("%d%d",&n,&k);
    cov=1+2*k;
    int ans=n/cov;
    if(n%cov)
    {
        ans++;
    }
    printf("%d\n",ans);
    vector<int> out;
    int pos=1;
    while(ans)
    {
        out.push_back(pos+k);
        pos+=cov;
        ans--;
    }
    int sub=out[out.size()-1]-n;
    if(sub<0)
    {
        sub=0;
    }
    for(int i=0;i<out.size();i++)
    {
        printf("%d ",out[i]-sub);
    }
    printf("\n");
    return 0;
}