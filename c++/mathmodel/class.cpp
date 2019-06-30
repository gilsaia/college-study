#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
map<string, int> tree;
struct book
{
	int words[7];
};
void check(ifstream& in, ofstream& out, int levelsize)
{
	book nowbook;
	for (int i = 0; i < levelsize; ++i)
	{
		nowbook.words[i] = 0;
	}
	string tmp;
	int start = 0;
	while (!in.eof())
	{
		in >> tmp;
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		nowbook.words[levelsize - 1]++;
		if (tree.find(tmp) == tree.end())
		{
			continue;
		}
		int numb = tree[tmp];
		nowbook.words[numb]++;
		// while(numb>=0)
		// {
		//     nowbook.words[numb]++;
		//     numb--;
		// }
	}
	for (int i = 0; i < levelsize; ++i)
	{
		out << nowbook.words[i] << endl;
	}
}
int main()
{
	string wordpath = "D:\\mathmodel\\word\\";
	stringstream ss;
	for (int i = 1; i <= 5; ++i)
	{
		ss << i;
		string tmp = wordpath + ss.str() + ".txt";
		ss.clear();
		ss.str("");
		ifstream inword(tmp);
		string word;
		while (!inword.eof())
		{
			inword >> word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			tree[word] = i - 1;
		}
	}
	string readin = "E:\\gg\\";
	string readout = "E:\\gge\\";
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
		check(in, out, 7);
		in.close();
		out.close();
	}
}