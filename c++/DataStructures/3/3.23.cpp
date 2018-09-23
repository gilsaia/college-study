#include<sstream>
#include<vector>
#include<stack>
using namespace std;
string transform(string h)
{
    istringstream record(h);
    string ans,tmp;
    stack<char> tmpsav;
    while(record>>tmp)
    {
        if(tmp[0]>='0'&&tmp[0]<='9')
        {
            ans+=tmp;
            ans+=' ';
        }
        else
        {
            switch(tmp[0])
            {
                case '+':
                while(tmpsav.size()&&(tmpsav.top()=='+'||tmpsav.top()=='-'||tmpsav.top()=='*'||tmpsav.top()=='/'||tmpsav.top()=='^'))
                {
                    ans+=tmpsav.top();
                    ans+=' ';
                    tmpsav.pop();
                }
                tmpsav.push('+');
                break;
                case '-':
                while(tmpsav.size()&&(tmpsav.top()=='+'||tmpsav.top()=='-'||tmpsav.top()=='*'||tmpsav.top()=='/'||tmpsav.top()=='^'))
                {
                    ans+=tmpsav.top();
                    ans+=' ';
                    tmpsav.pop();
                }
                tmpsav.push('-');
                break;
                case '*':
                while(tmpsav.size()&&(tmpsav.top()=='*'||tmpsav.top()=='/'||tmpsav.top()=='^'))
                {
                    ans+=tmpsav.top();
                    ans+=' ';
                    tmpsav.pop();
                }
                tmpsav.push('*');
                break;
                case '/':
                while(tmpsav.size()&&(tmpsav.top()=='*'||tmpsav.top()=='/'||tmpsav.top()=='^'))
                {
                    ans+=tmpsav.top();
                    ans+=' ';
                    tmpsav.pop();
                }
                tmpsav.push('/');
                break;
                case '(':
                while(tmpsav.size()&&(tmpsav.top=='^'))
                {
                    ans+=tmpsav.top();
                    ans+=' ';
                    tmpsav.pop();
                }
                tmpsav.push('(');
                break;
                case ')':
                while(tmpsav.size()&&tmpsav.top()!='(')
                {
                    ans+=tmpsav.top();
                    ans+=' ';
                    tmpsav.pop();
                }
                tmpsav.pop();
                break;
                case '^':
                tmpsav.push('^');
                break;
                default:break;
            }
        }
    }
    return ans;
}