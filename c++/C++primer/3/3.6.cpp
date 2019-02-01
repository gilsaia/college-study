#include<string>
using std::string;
string change(string input)
{
    for(auto &c:input)
    {
        c='X';
    }
    return input;
}