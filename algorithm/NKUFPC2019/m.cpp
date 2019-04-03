#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    cout<<0<<endl;
    string toinput,tooutput;
    int x,y;
    cin>>toinput>>x>>y>>tooutput;
    ifstream input(toinput);
    ofstream output(tooutput);
    for(int i=1;i<x;++i)
    {
        if(input.eof())
        {
            cout<<"failed"<<endl;
            input.close();
            output.close();
            return 0;
        }
        string tmp;
        getline(input,tmp);
    }
    for(int i=1;i<y;++i)
    {
        if(input.eof())
        {
            cout<<"failed"<<endl;
            input.close();
            output.close();
            return 0;
        }
        char tmp;
        input.get(tmp);
    }
    char tmp;
    input.get(tmp);
    int result,num=0;
    string result2;
    if(tmp>='0'&&tmp<='9')
    {
        input.seekg(-1,ios::cur);
        input>>result;
        num=1;
    }
    else if((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z'))
    {
        input.seekg(-1,ios::cur);
        input>>result2;
        num=2;
    }
    else
    {
        cout<<"unsure"<<endl;
        input.close();
        output.close();
        return 0;
    }
    if(output.fail())
    {
        cout<<"access denied"<<endl;
        input.close();
        output.close();
        return 0;
    }
    if(num==1)
    {
        output<<result<<endl;
    }
    else if(num==2)
    {
        output<<result2<<endl;
    }
    cout<<"ok"<<endl;
    input.close();
    output.close();
    return 0;
}