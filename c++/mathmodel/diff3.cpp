#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
    int num;
    double diff,sum;
};
int main()
{
    vector<node> vec;
	string readin = "D:\\mathmodel\\data\\ggds\\diffres.txt";
	string readout = "D:\\mathmodel\\data\\ggds\\diffress.txt";
    ifstream in(readin);
    ofstream out(readout);
    double maxdiff=0,maxsum=0;
    while(!in.eof())
    {
        node tmp;
        in>>tmp.num>>tmp.diff>>tmp.sum;
        maxdiff+=tmp.diff;
        maxsum+=tmp.sum;
        vec.push_back(tmp);
    }
    for(int i=0;i<vec.size();++i)
    {
        vec[i].diff=vec[i].diff*=10000;
        vec[i].sum*=10000;
    }
    for(int i=0;i<vec.size();++i)
    {
        out<<vec[i].num<<"   "<<vec[i].diff<<"   "<<vec[i].sum<<endl;
    }
    return 0;
}