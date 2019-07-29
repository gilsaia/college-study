#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int num,raw,col,from,froraw,frocol;
    bool operator<(const node &rhs)const
    {
        return num>rhs.num;
    }
};
vector<node> numbers[3020];
int save[120][5][5];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<5;++j)
        {
            for(int m=0;m<5;++m)
            {
                scanf("%d",&save[i][j][m]);
                node tmp;
                tmp.num=i,tmp.raw=j,tmp.col=m;
                numbers[save[i][j][m]].push_back(tmp);
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=0;i<n;++i)
    {
        priority_queue<node> que;
        for(int j=0;j<5;++j)
        {
            for(int t=0;t<5;++t)
            {
                int tmp=save[i][j][t];
                if(numbers[tmp].size()>1)
                {
                    for(int m=0;m<numbers[tmp].size();++m)
                    {
                        node tmpnod=numbers[tmp][m];
                        if(tmpnod.num<=i)
                        {
                            continue;
                        }
                        tmpnod.from=i,tmpnod.froraw=j,tmpnod.frocol=t;
                        que.push(tmpnod);
                    }
                }
            }
        }
        while(!que.empty())
        {
            node tmp=que.top();
            que.pop();
            vector<int> findguess;
            for(int j=0;j<5;++j)
            {
                if(j==tmp.frocol)
                {
                    continue;
                }
                findguess.push_back(save[tmp.from][tmp.froraw][j]);
            }
            for(int j=0;j<5;++j)
            {
                if(j==tmp.col)
                {
                    continue;
                }
                findguess.push_back(save[tmp.num][tmp.raw][j]);
            }
            int tieres=0;
            for(int j=0;j<5;++j)
            {
                if(j==tmp.frocol)
                {
                    continue;
                }
                int findval=save[tmp.from][tmp.froraw][tmp.frocol];
                int findres=0;
                for(int t=0;t<numbers[findval].size();++t)
                {
                    if(numbers[findval][t].num==tmp.from)
                    {
                        continue;
                    }
                    node guess=numbers[findval][t];
                    int rawres=1;
                    for(int m=0;m<5;++m)
                    {
                        int colres=0;
                        for(int q=0;q<findguess.size();++q)
                        {
                            if(save[guess.num][guess.raw][m]==findguess[q])
                            {
                                colres=1;
                                break;
                            }
                        }
                        if(colres==0)
                        {
                            rawres=0;
                            break;
                        }
                    }
                    if(rawres==1)
                    {
                        findres=1;
                        break;
                    }
                }
                if(findres==1)
                {
                    tieres=1;
                    break;
                }
            }
            for(int j=0;j<5;++j)
            {
                if(j==tmp.num)
                {
                    continue;
                }
                int findval=save[tmp.num][tmp.raw][tmp.col];
                int findres=0;
                for(int t=0;t<numbers[findval].size();++t)
                {
                    if(numbers[findval][t].num==tmp.num)
                    {
                        continue;
                    }
                    node guess=numbers[findval][t];
                    int rawres=1;
                    for(int m=0;m<5;++m)
                    {
                        int colres=0;
                        for(int q=0;q<findguess.size();++q)
                        {
                            if(save[guess.num][guess.raw][m]==findguess[q])
                            {
                                colres=1;
                                break;
                            }
                        }
                        if(colres==0)
                        {
                            rawres=0;
                            break;
                        }
                    }
                    if(rawres==1)
                    {
                        findres=1;
                        break;
                    }
                }
                if(findres==1)
                {
                    tieres=1;
                    break;
                }
            }
            if(tieres==0)
            {
                ans1=tmp.from,ans2=tmp.num;
                break;
            }
        }
        if(ans1!=0)
        {
            break;
        }
    }
    if(ans1==0)
    {
        printf("no ties\n");
    }
    else
    {
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}