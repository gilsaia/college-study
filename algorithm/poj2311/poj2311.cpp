//奇怪的grundy值例题···
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int mem[220][220];
int grundy(int w,int h)
{
    if(mem[w][h]!=-1)
    {
        return mem[w][h];
    }
    set<int> s;
    for(int i=2;w-i>=2;++i)
    {
        s.insert(grundy(i,h)^grundy(w-i,h));
    }
    for(int i=2;h-i>=2;++i)
    {
        s.insert(grundy(w,i)^grundy(w,h-i));
    }
    int res=0;
    while(s.count(res)){
        res++;
    }
    return mem[w][h]=res;
}
int main()
{
    int w,h;
    for(int i=0;i<=220;++i)
    {
        for(int j=0;j<=220;++j)
        {
            mem[i][j]=-1;
        }
    }
    while(~scanf("%d%d",&w,&h))
    {
        if(grundy(w,h)!=0)
        {
            printf("WIN\n");
        }
        else
        {
            printf("LOSE\n");
        }
    }
    return 0;
}