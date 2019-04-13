#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<utility>
using namespace std;
struct DicTrie
{
    int count;
    map<int,DicTrie *> Node;
    DicTrie()
    {
        count=0;
    }
    ~DicTrie()
    {
        for(auto i=Node.begin();i!=Node.end();++i)
        {
            delete i->second;
        }
    }
};
int check(DicTrie *now)
{
    int ans=0,nowcount=now->count;
    for(auto i=now->Node.begin();i!=now->Node.end();++i)
    {
        int tmp=check(i->second);
        ans+=tmp;
        nowcount-=tmp;
    }
    if(nowcount>=2)
    {
        ans+=2;
    }
    return ans;
}
int main()
{
    int T;
    cin>>T;
    for(int m=1;m<=T;++m)
    {
        int N;
        cin>>N;
        DicTrie *root=new DicTrie();
        for(int i=0;i<N;++i)
        {
            string tmp;
            cin>>tmp;
            DicTrie *cur=root;
            for(int j=tmp.size()-1;j>=0;--j)
            {
                if(cur->Node.find(tmp[j]-'A')==cur->Node.end())
                {
                    DicTrie *cre=new DicTrie();
                    ++cre->count;
                    cur->Node.insert(pair<int,DicTrie *>(tmp[j]-'A',cre));
                    cur=cre;
                }
                else
                {
                    cur=cur->Node[tmp[j]-'A'];
                    ++cur->count;
                }
            }
        }
        int ans=check(root);
        cout<<"Case #"<<m<<": "<<ans<<endl;
        delete root;
    }
    return 0;
}