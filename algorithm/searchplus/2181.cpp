#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int path[25][4];
struct node
{
    vector<int> path;
    int condition;
};
int num;
void dfs(node &now,int &start,int passstart,int nowpos,bool startcon)
{
    // if(passstart==3&&start!=startcon)
    // {
    //     return;
    // }
    if(start==nowpos&&startcon==0)
    {
        if(now.condition!=((1<<21)-2))
        {
            return;
        }
        printf("%d: ",num);
        ++num;
        for(int i=0;i<now.path.size();++i)
        {
            printf(" %d",now.path[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<3;++i)
    {
        if(path[nowpos][i]==start)
        {
            ++passstart;
        }
        if(!(now.condition>>path[nowpos][i]&1))
        {
            now.path.push_back(path[nowpos][i]);
            now.condition|=1<<path[nowpos][i];
            dfs(now,start,passstart,path[nowpos][i],0);
            now.path.pop_back();
            now.condition&=(~(1<<path[nowpos][i]));
        }
    }
}
int main()
{
    for(int i=1;i<=20;++i)
    {
        for(int j=0;j<3;++j)
        {
            scanf("%d",&path[i][j]);
        }
        for(int j=0;j<2;++j)
        {
            if(path[i][j]>path[i][j+1])
            {
                swap(path[i][j],path[i][j+1]);
            }
        }
    }
    int start;
    while(scanf("%d",&start),start)
    {
        node tmp;
        tmp.condition=0;
        tmp.path.push_back(start);
        num=1;
        dfs(tmp,start,0,start,1);
    }
    return 0;
}