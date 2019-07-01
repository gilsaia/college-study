#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
using namespace std;
const int MINIUM=5000;
void check(ifstream &in,string sout)
{
    int diff[6];
    int sum=0;
    for(int i=0;i<5;++i)
    {
        in>>diff[i];
        sum+=diff[i];
    }
    if(sum<MINIUM)
    {
        return;
    }
    ofstream out(sout);
    double difficult[6];
    double res=0;
    for(int i=0;i<5;++i)
    {
        difficult[i]=(double)diff[i]/(double)sum;
        res+=difficult[i]*(i+1)*1000;
    }
    out<<res<<endl<<sum<<endl;
    out.close();
}
int main()
{
    string readin = "D:\\mathmodel\\data\\gge\\";
	string readout = "D:\\mathmodel\\data\\ggd\\";
	stringstream sse;
	// ifstream in("D:\\mathmodel\\data\\gge\\11.txt");
	// ofstream out("D:\\mathmodel\\data\\ggd\\11.txt");
    // check(in,out);
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
		check(in, tmp);
		in.close();
	}
}