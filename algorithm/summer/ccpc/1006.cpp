#include<cstdio>
#include<stack>
using namespace std;
int used[100030];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    stack<int> res,find;
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        find.push(tmp);
    }
    while(!find.empty())
    {
        res.push(find.top());
        find.pop();
    }
    for(int i=0;i<m;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        res.push(tmp);
    }
    while(!res.empty())
    {
        int out=res.top();
        if(used[out]==0)
        {
            used[out]=1;
            printf("%d ",out);
        }
        res.pop();
    }
    return 0;
}