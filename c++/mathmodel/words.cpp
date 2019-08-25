#include<fstream>
#include<string>
#include<sstream>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ifstream in("D:\\mathmodel\\word\\GRE_delete_CET4+6+TOEFL.txt");
    ofstream out("D:\\mathmodel\\word\\5.txt");
    char tmp[300];

    while(!in.eof())
    {
        in.getline(tmp,300);
        char *res=strtok(tmp," ");
        if(res==NULL)
        {
            continue;
        }
        out<<res<<endl;
    }
    return 0;
}