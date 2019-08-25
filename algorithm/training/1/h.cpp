#include<cstdio>
#include<algorithm>
using namespace std;
int res[100020];
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;++i)
    {
        scanf("%d",&res[i]);
    }
    sort(res,res+N);
    if(K>N-1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",res[N-K-1]);
    }
    return 0;
}