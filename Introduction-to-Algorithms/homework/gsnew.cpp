#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=32;
int manlist[MAXN][MAXN],womanlist[MAXN][MAXN];
int manchoose[MAXN],womanchoose[MAXN],ans[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
       for(int j=1;j<=n;++j)
       {
           scanf("%d",&manlist[i][j]);
       }
       manchoose[i]=1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            womanlist[i][tmp]=j;
        }
        womanchoose[i]=-1;
    }
    stack<int> maninlist;
    for(int i=1;i<=n;++i)
    {
        maninlist.push(i);
        while(!maninlist.empty()){
            int num=maninlist.top();
            maninlist.pop();
            int wonum=manlist[num][manchoose[num]];
            if(womanchoose[wonum]==-1)
            {
                womanchoose[wonum]=num;
                continue;
            }
            int oldman=womanchoose[wonum];
            if(womanlist[wonum][oldman]>womanlist[wonum][num])
            {
                womanchoose[wonum]=num;
                manchoose[oldman]++;
                maninlist.push(oldman);
                continue;
            }
            manchoose[num]++;
            maninlist.push(num);
        }
    }
    for(int i=1;i<=n;++i)
    {
        ans[womanchoose[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}