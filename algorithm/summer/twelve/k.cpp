#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
pair<int,int> code[100020];
int res[100020];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&code[i].first);
        code[i].second=i+1;
    }
    sort(code,code+n);
    for(int i=1;i<=n;++i)
    {
        res[code[n-i].second]=i;
    }
    for(int i=1;i<=n;++i)
    {
        printf("%d ",res[i]);
    }
    printf("\n");
    return 0;
}