#include<cstdio>
#include<algorithm>
using namespace std;
int stu[100020];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        int N,P;
        int ans;
        scanf("%d%d",&N,&P);
        for(int j=0;j<N;++j)
        {
            scanf("%d",&stu[j]);
        }
        sort(stu,stu+N);
        int sum=0;
        for(int j=0;j<P;++j)
        {
            sum+=stu[P-1]-stu[j];
        }
        ans=sum;
        for(int j=P;j<N;++j)
        {
            sum-=(stu[j-1]-stu[j-P]);
            sum+=(stu[j]-stu[j-1])*(P-1);
            ans=min(ans,sum);
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}