#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    set<int> haverecive;
    queue<int> display;
    int nowdis=0;
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        if(haverecive.find(tmp)==haverecive.end())
        {
            if(nowdis<k)
            {
                ++nowdis;
                display.push(tmp);
                haverecive.insert(tmp);
            }
            else
            {
                int tocle=display.front();
                display.pop();
                haverecive.erase(tocle);
                display.push(tmp);
                haverecive.insert(tmp);
            }
        }
    }
    printf("%d\n",nowdis);
    stack<int> que;
    while(!display.empty())
    {
        que.push(display.front());
        display.pop();
    }
    for(int i=0;i<nowdis;++i)
    {
        printf("%d ",que.top());
        que.pop();
    }
    printf("\n");
    return 0;
}