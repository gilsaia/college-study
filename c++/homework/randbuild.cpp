#include<iostream>
#include<fstream>
#include<algorithm>
#include<random>
#include<ctime>
#include<iomanip>
using std::ostream;
using std::ofstream;
using std::default_random_engine;
using std::time;
using std::uniform_int_distribution;
using std::normal_distribution;
using std::endl;
using std::setw;
const int size=10000;
const int ENDL=20;
int main()
{
    ofstream out("G:\\cs\\coding\\c++\\homework\\randnumber.txt");
    default_random_engine send(time(0));
    //uniform_int_distribution<int> dis(-100000,100000);
    normal_distribution<> dis(0,10000);
    for(int i=0;i<size;)
    {
        int tmp=dis(send);
        out<<setw(6)<<tmp;
        if(++i%ENDL==0)
        {
            out<<endl;
        }
        else
        {
            out<<" ";
        }
    }
    return 0;
}