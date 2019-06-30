#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
using namespace std;
void check(ifstream &in,ofstream &out)
{
    
}
int main()
{
    string readin = "D:\\mathmodel\\data\\gge\\";
	string readout = "D:\\mathmodel\\data\\ggd\\";
	stringstream sse;
	ifstream in;
	ofstream out;
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
		out.open(tmp);
		check(in, out);
		in.close();
		out.close();
	}
}