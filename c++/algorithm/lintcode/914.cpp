#include<vector>
#include<string>
using namespace std;
vector<string> generatePossibleNextMoves(string &s) {
        vector<string> temp;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='+'&&s[i+1]=='+')
            {
                string a=s;
                a[i]='-';
                a[i+1]='-';
                temp.push_back(a);
            }
        }
        return temp;