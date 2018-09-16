#ifndef CHECK_H
#define CHECK_H
#include<string>
#include<stack>
using namespace std;
void check(string h)
{
    stack<char> ccc;
    for(int i=0;i<h.size();i++)
    {
        switch(h[i])
        {
            case '/':
            if(i+1<h.size()&&h[i+1]=='*')
            {
                ccc.push('/');
                ccc.push('*');
                i++;
            }
            break;
            case '(':
            ccc.push('(');
            break;
            case '[':
            ccc.push('[');
            break;
            case '{':
            ccc.push('{');
            break;
            case ')':
            if(ccc.empty())
            {
                throw "isempty";
            }
            else if(ccc.top()!='(')
            {
                throw "cannotbecompiled";
            }
            else
            {
                ccc.pop();
            }
            break;
            case ']':
            if(ccc.empty())
            {
                throw "isempty";
            }
            else if(ccc.top()!='[')
            {
                throw "cannotbecompiled";
            }
            else
            {
                ccc.pop();
            }
            break;
            case '}':
            if(ccc.empty())
            {
                throw "isempty";
            }
            else if(ccc.top()!='{')
            {
                throw "cannotbecompiled";
            }
            else
            {
                ccc.pop();
            }
            break;
            case '*':
            if(i+1<h.size()&&h[i+1]=='/')
            {
                 if(ccc.empty())
                {
                    throw "isempty";
                }
                else if(ccc.top()!='*')
                {
                    throw "cannotbecompiled";
                }
                else
                {
                    ccc.pop();
                    ccc.pop();
                    i++;
                }
            }
            break;
            default:break;
        }
    }
    if(!ccc.empty())
    {
        throw "wrong";
    }
}
#endif