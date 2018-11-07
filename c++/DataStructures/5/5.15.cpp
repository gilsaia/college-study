#include<string>
#include<vector>
using namespace std;
size_t hashstr(const string &a)
{
    size_t hashval=0;
    for(char ch:a)
    {
        hashval=37*hashval+ch;
    }
    return hashval;
}
size_t findsubstr(string &root,string &find)
{
    size_t tofind=hashstr(find);
    int i=find.size();
    for(int t=0;t+i<root.size();++t)
    {
        size_t update=hashstr(root.substr(t,t+i));
        if(update==tofind)
        {
            string tmp=root.substr(t,t+i);
            if(tmp==find)
            {
                return t;
            }
        }
    }
    return root.size();
}