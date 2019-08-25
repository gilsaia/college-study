#include<iostream>
#include<string>
using namespace std;
int maps[5][5];
int unknowx,unknowy;
char ope[4]={'l','r','u','d'};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int dfs(string &opr,int step,int nowstep,int currig)
{
    if(nowstep>step)
    {
        return 0;
    }
    if(currig==8)
    {
        return 1;
    }
    for(int i=0;i<4;++i)
    {
        if(maps[unknowx+dx[i]][unknowy+dy[i]]!=0)
        {
            
            int old=maps[unknowx+dx[i]][unknowy+dy[i]];
            maps[unknowx][unknowy]=old;
            if(old==(unknowx-1)*3+unknowy)
            {
                ++currig;
            }
            unknowx+=dx[i];
            unknowy+=dy[i];
            if(old==(unknowx-1)*3+unknowy)
            {
                --currig;
                unknowx-=dx[i];
                unknowy-=dy[i];
                continue;
            }
            opr+=ope[i];
            int res=dfs(opr,step,nowstep+1,currig);
            if(res==1)
            {
                return 1;
            }
            maps[unknowx][unknowy]=old;
            unknowx-=dx[i];
            unknowy-=dy[i];
            opr.pop_back();
        }
    }
    return 0;
}
int main()
{
    char tmp;
    int rightnum=0;
    for(int i=0;i<9;++i)
    {
        cin>>tmp;
        if(tmp=='x')
        {
            unknowx=1+i/3;
            unknowy=1+i-(unknowx-1)*3;
            maps[1+i/3][1+i-i/3*3]=9;
        }
        else
        {
            maps[1+i/3][1+i-i/3*3]=tmp-'0';
            if((i+1)==tmp-'0')
            {
                ++rightnum;
            }
        }
    }
    string res;
    int step=0,ans;
    do
    {
        ++step;
        ans=dfs(res,step,0,rightnum);
        if(ans==-1)
        {
            break;
        }
    }
    while(ans!=1);
    if(ans==-1)
    {
        cout<<"unsolvable"<<endl;
    }
    else
    {
        cout<<res<<endl;
    }
    return 0;
}