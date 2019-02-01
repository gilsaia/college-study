#include<string>
#include<cctype>
using std::string;
using std::ispunct;
string change(string input)
{
    string tmp;
    for(auto c:input)
    {
        if(!ispunct(c))
        {
            tmp+=c;
        }
    }
    return tmp;
}