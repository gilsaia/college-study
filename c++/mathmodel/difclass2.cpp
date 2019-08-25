#include<fstream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
using namespace std;
struct node
{
    int num;
    long double value;
    bool operator<(const node &rhs) const
    {
        return value>rhs.value;
    }
};
priority_queue<node> que;
void read(string inputpath)
{
    int num;
    double diff,sum;
    ifstream in(inputpath);
    while(!in.eof())
    {
        in>>num>>diff>>sum;
        node tmp;
        tmp.num=num;
        tmp.value=diff*diff+sum*sum;
        que.push(tmp);
    }
}
const int MAX_CLASS=10;
int main()
{
	string inputpath = "D:\\mathmodel\\data\\ggds\\diffress.txt";
	string outputpath = "D:\\mathmodel\\data\\ggds\\diffresel.txt";
	read(inputpath);
    int num=que.size()/MAX_CLASS;
    ofstream out("D:\\mathmodel\\data\\ggds\\diffresel.txt");
    for(int i=0;i<MAX_CLASS;++i)
    {
		out << "第" << i+1 << "档难度的书为如下编号:" << endl;
		for (int j = 0; j < num; ++j)
		{
			out << que.top().num << endl;
            que.pop();
		}
    }
    while(!que.empty())
    {
        out<<que.top().num<<endl;
        que.pop();
    }
    return 0;
}