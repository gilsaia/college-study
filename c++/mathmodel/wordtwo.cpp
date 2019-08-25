#include<fstream>
#include<string>
#include<sstream>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ifstream in("D:\\mathmodel\\word\\2.txt");
    ofstream out("D:\\mathmodel\\word\\02.txt");
    string tmp;
    while(!in.eof())
    {
        in>>tmp;
        out<<tmp.substr(0,tmp.find('['))<<endl;
    }
    return 0;
}