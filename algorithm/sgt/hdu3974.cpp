#include <cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 50005;
struct employee{
    int task, t;
} e[N];
int par[N];
 
int main()
{
    int cas, a, b, n, m;
    char op[5];
    scanf("%d", &cas);
    for(int k = 1; k <= cas; ++k)
    {
        printf("Case #%d:\n", k);
        memset(par, -1, sizeof(par));
        scanf("%d", &n);
        for(int i = 1; i < n; ++i)
        {
            e[i].t = e[i].task = 0;
            scanf("%d%d", &a, &b), par[a] = b;
        }
        e[n].t = e[n].task = 0;
 
        scanf("%d", &m);
        int t = 0, last, ans;
        while(m--)
        {
            scanf("%s%d", op, &a);
            if(op[0] == 'C')
            {
                last = 0;//所有祖先节点最晚任务的时间
                while(a != -1)
                {
                    if(e[a].t > last)
                        last = e[a].t, ans = e[a].task;
                    a = par[a];
                }
                printf("%d\n", last ? ans : -1);
            }
            else
            {
                scanf("%d", &b);
                e[a].task = b, e[a].t = ++t;
            }
        }
    }
    return 0;
}