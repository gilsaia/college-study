#include<iostream>
#include<set>
#include<algorithm>
#include<stack>
#include<utility>
using namespace std;
int R,C;
int dfs(int x,int y,set<pair<int,int>> &path,stack<pair<int,int>> &seq)
{
    pair<int,int> tmp(x,y);
    path.insert(tmp);
    seq.push(tmp);
    if(seq.size()==R*C)
    {
        return 1;
    }
    for(int i=1;i<=R;++i)
    {
        for(int j=1;j<=C;++j)
        {
            if(i!=tmp.first&&j!=tmp.second&&(i+j)!=(tmp.first+tmp.second)&&(i-j)!=(tmp.first-tmp.second))
            {
                pair<int,int> now(i,j);
                if(path.find(now)==path.end())
                {
                    if(dfs(i,j,path,seq))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    path.erase(tmp);
    seq.pop();
    return 0;
}
int main()
{
    int T;
    cin>>T;
    for(int m=1;m<=T;++m)
    {
        cin>>R>>C;
        set<pair<int,int>> path;
        stack<pair<int,int>>seq;
        cout<<"Case #"<<m<<": ";
        if(dfs(1,1,path,seq))
        {
            cout<<"POSSIBLE"<<endl;
            while(!seq.empty())
            {
                pair<int,int> tmp=seq.top();
                seq.pop();
                cout<<tmp.first<<" "<<tmp.second<<endl;
            }
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}