#include<cstdio>
#include<algorithm>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        que.push(tmp);
    }
    int tosub=0;
    for(int i=0;i<k;++i)
    {
        int findmin=0;
        while(!que.empty())
        {
            findmin=que.top()-tosub;
            if(findmin>0)
            {
                break;
            }
            que.pop();
        }
        if(findmin>0)
        {
            printf("%d\n",findmin);
            que.push(findmin+tosub);
        }
        else
        {
            printf("0\n");
        }
        tosub+=findmin;
    }
    return 0;
}