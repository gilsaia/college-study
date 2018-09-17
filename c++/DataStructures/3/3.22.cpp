#ifndef POLAN_H
#define POLAN_H
#include<stack>
#include<sstream>
#include<vector>
#include<cstdlib>
using namespace std;
double polan(string s)
{
    stack<double> tocal;
    vector<string> change;
    istringstream record(s);
    string tmp;
    while(record>>tmp)
    {
        change.push_back(tmp);
    }
    for(int i=0;i<change.size();i++)
    {
        if(change[i][0]>='0'&&change[i][0]<='9')
        {
            double temp=0;
            char save[100];
            int j=0;
            for(j=0;j<change[i].size();j++)
            {
                save[j]=change[i][j];
            }
            save[j]='\0';
            temp=atof(save);
            tocal.push(temp);
        }
        else
        {
            switch(change[i][0])
            {
                case '+':
                double temp1;
                temp1=tocal.top();
                tocal.pop();
                temp1+=tocal.top();
                tocal.pop();
                tocal.push(temp1);
                break;
                case '-':
               double temp1;
                temp1=tocal.top();
                tocal.pop();
                double temp2=tocal.top();
                tocal.pop();
                temp1=temp2-temp1;
                tocal.push(temp1);
                break;
                case '*':
                double temp1;
                temp1=tocal.top();
                tocal.pop();
                temp1*=tocal.top();
                tocal.pop();
                tocal.push(temp1);
                break;
                case '/':
                double temp1;
                temp1=tocal.top();
                tocal.pop();
                double temp2=tocal.top();
                tocal.pop();
                temp1=temp2/temp1;
                tocal.push(temp1);
                break;
                default:break;
            }
        }
    }
    return tocal.top();
}
#endif