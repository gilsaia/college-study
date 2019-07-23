#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
    vector<int> contains;
    ll nowdif;
    node *next[27];
    node()
    {
        for(int i=0;i<26;++i)
        {
            next[i]=NULL;
        }
    }
};
node start;
ll dif[27];
int n,m;
ll strdif[100020];
ll sum[100020];
void strpro(string &str,int num)
{
    node *point=&start;
    ll score=1;
    for(int i=0;i<str.size();++i)
    {
        if(point->next[str[i]-'a']==NULL)
        {
            point->next[str[i]-'a']=new node;
        }
        point=point->next[str[i]-'a'];
        point->contains.push_back(num);
        score=(score*dif[str[i]-'a'])%m;
        point->nowdif=score;
    }
    strdif[num]=score;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<26;++i)
    {
        cin>>dif[i];
    }
    for(int i=0;i<n;++i)
    {
        string tmp;
        cin>>tmp;
        strpro(tmp,i);
    }
    queue<node *> que;
    que.push(&start);
    while(!que.empty())
    {
        node *tmp=que.front();
        que.pop();
        for(int i=0;i<26;++i)
        {
            if(tmp->next[i]!=NULL)
            {
                node *next=tmp->next[i];
                for(int j=0;j<next->contains.size();++j)
                {
                    if(next->nowdif>strdif[next->contains[j]])
                    {
                        sum[next->contains[j]]+=next->contains.size();
                    }
                }
                que.push(next);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    return 0;
}