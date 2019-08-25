#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
double maxdif=0;
double maxlength=0;
struct node
{
    int num;
    double diff,sum;
};
void check(ifstream &in,node &tte)
{
    in>>tte.diff>>tte.sum;
    maxdif=max(maxdif,tte.diff);
    maxlength=max(maxlength,tte.sum);
}
int main()
{
    vector<node> vec;
	string readin = "D:\\mathmodel\\data\\ggd\\";
	string readout = "D:\\mathmodel\\data\\ggds\\";
	stringstream sse;
	ifstream in;
	for (int i = 1; i < 60000; ++i)
	{
		sse << i;
		string tmp = readin + sse.str() + ".txt";
		in.open(tmp);
		if (!in)
		{
			in.close();
			sse.str("");
			continue;
		}
		tmp = readout + sse.str() + ".txt";
		sse.clear();
		sse.str("");
        node tte;
        tte.num=i;
		check(in,tte);
        vec.push_back(tte);
		in.close();
	}
    for(int i=0;i<vec.size();++i)
    {
        vec[i].diff/=maxdif;
        vec[i].sum/=maxlength;
    }
    string outpath=readout+"diffres.txt";
    ofstream out(outpath);
    for(int i=0;i<vec.size();++i)
    {
        out<<vec[i].num<<"   "<<vec[i].diff<<"   "<<vec[i].sum<<endl;
    }
    return 0;
}