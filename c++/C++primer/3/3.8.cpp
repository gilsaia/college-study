#include<string>
using std::string;
string change(string input)
{
    for(size_t i=0;i<input.size();++i)
    {
        input[i]='X';
    }
    return input;
}
string change2(string input)
{
    size_t i=0;
    while(i<=input.size())
    {
        input[i++]='X';
    }
    return input;
}