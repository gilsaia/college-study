#include<cstdio>
#include<random>
using namespace std;
const int edge=1000000;
const int node=1000000;
int main()
{
    freopen("in.txt","w",stdout);
    printf("%d %d\n",edge,node);
    uniform_int_distribution<int> eee(1,999999);
    uniform_int_distribution<int> ddd(1,1020);
    default_random_engine e(123182);
    for(int i=0;i<edge;++i)
    {
        printf("%d %d %d\n",eee(e),eee(e),ddd(e));
    }
    return 0;
}