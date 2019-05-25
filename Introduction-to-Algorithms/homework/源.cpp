#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<ios>
using std::vector;
using std::lower_bound;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::min;
using std::max;
using std::string;
using std::ios;
using std::sort;
using std::cout;
using std::cin;
const int N = 100;
const int D = 1e4;
int dp[N + 1][D];
struct word
{
	int index, difficult, value;
	string word1;
};
vector<int> torecite(vector<int> &S, vector<int> &d, vector<int> &v)
{
	vector<int> **findpath;
	findpath = new vector<int> * [N + 1];
	for (int i = 0; i <= N; ++i)
	{
		findpath[i] = new vector<int>[D];
	}
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j<D; ++j)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i<S.size(); ++i)
	{
		for (int j = min(i + 1, N); j>0; --j)
		{
			for (int t = D - 1; t >= d[i]; --t)
			{
				if ((dp[j - 1][t - d[i]] + v[i])>dp[j][t])
				{
					dp[j][t] = dp[j - 1][t - d[i]] + v[i];
					findpath[j][t].push_back(i);
				}
			}
		}
	}
	int ssize = S.size();
	int num = min(ssize, N);
	vector<int> index;
	int maxnum = S.size() + 1, nowdifficult = D - 1;
	for (int i = 0; i<num; ++i)
	{
		auto tofind = lower_bound(findpath[num - i][nowdifficult].begin(), findpath[num - i][nowdifficult].end(), maxnum);
		--tofind;
		int tmp = *tofind;
		index.push_back(S[*tofind]);
		maxnum = tmp + 1, nowdifficult -= d[tmp];
	}
	for (int i = 0; i <= N; ++i)
		delete[]findpath[i];
	delete[]findpath;
	return index;
}
const int circle[6] = { 0,1,2,4,7,15 };
const int cirvalue[6] = { 1,1,1,1,1,1 };
const int mustrecite = 20;
void daypro(string filedir[7])
{
	ifstream read1(filedir[0]), read2(filedir[1]), read3(filedir[2]), read4(filedir[3]), read5(filedir[4]), read6(filedir[5]), read7(filedir[6]);
	ofstream write[6];
	vector<word> store[7];
	int index = 0;
	word tmp1;
	while (!read1.eof())
	{
		read1 >> tmp1.word1;
		read1 >> tmp1.difficult;
		if (tmp1.difficult == -858993460)
			break;
		tmp1.value = 1;
		tmp1.index = index++;
		store[0].push_back(tmp1);
	}
	word tmp2;
	while (!read2.eof())
	{
		read2 >> tmp2.word1;
		read2 >> tmp2.difficult;
		if (tmp2.difficult == -858993460)
			break;
		read2 >> tmp2.value;
		tmp2.index = index++;
		store[1].push_back(tmp2);
	}
	word tmp3;
	while (!read3.eof())
	{
		read3 >> tmp3.word1;
		read3 >> tmp3.difficult;
		if (tmp3.difficult == -858993460)
			break;
		read3 >> tmp3.value;
		tmp3.index = index++;
		store[2].push_back(tmp3);
	}
	word tmp4;
	while (!read4.eof())
	{
		read4 >> tmp4.word1;
		read4 >> tmp4.difficult;
		if (tmp4.difficult == -858993460)
			break;
		read4 >> tmp4.value;
		tmp4.index = index++;
		store[3].push_back(tmp4);
	}
	word tmp5;
	while (!read5.eof())
	{
		read5 >> tmp5.word1;
		read5 >> tmp5.difficult;
		if (tmp5.difficult == -858993460)
			break;
		read5 >> tmp5.value;
		tmp5.index = index++;
		store[4].push_back(tmp5);
	}
	word tmp6;
	while (!read6.eof())
	{
		read6 >> tmp6.word1;
		read6 >> tmp6.difficult;
		if (tmp6.difficult == -858993460)
			break;
		read6 >> tmp6.value;
		tmp6.index = index++;
		store[5].push_back(tmp6);
	}
	/*以此类推读入六个文件的单词(注意除了第一个表其他表默认所有单词都有价值需要读入)*/
	vector<int> S, d, v, beforerecite;
	for (int i = 0; i<6; ++i)
	{
		for (int j = 0; j<store[i].size(); ++j)
		{
			if (store[i][j].value<circle[i])
			{
				++store[i][j].value;
			}
			else if (store[i][j].value >= mustrecite)
			{
				beforerecite.push_back(store[i][j].index);
			}
			else
			{
				S.push_back(store[i][j].index);
				d.push_back(store[i][j].difficult);
				v.push_back(store[i][j].value*cirvalue[i]);
			}
		}
	}
	vector<int> res;
	res = torecite(S, d, v);
	for (int i = 0; i<beforerecite.size(); ++i)
	{
		res.push_back(beforerecite[i]);//压入价值超过阈值的单词
	}
	sort(res.begin(), res.end());//最后得到的今天要背诵的单词索引表
	vector<string> list;
	int resnum = 0;
	for (int i = 0; i<6; ++i)
	{
		for (int j = 0; j<store[i].size(); ++j)
		{
			if (resnum<res.size())
			{
				if (res[resnum] == store[i][j].index)
				{
					list.push_back(store[i][j].word1);
					resnum++;
				}
			}
			else
			{
				break;
			}
		}
	}
	cout << "经计算，以下单词为今日需要背诵的单词：" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << ' ';
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
	cout << "请根据背诵情况写下相应单词的背诵结果，0表示轻松背会，1表示费劲" << endl;
	vector<int> reciteres;
	for (int i = 0; i < list.size(); ++i)
	{
		int tmp;
		cin >> tmp;
		reciteres.push_back(tmp % 2);
	}
	/*list即为背诵单词表，在这里进行交互操作来获得背诵情况?
????这里假设reciteres得到的为对应单词的背诵结果，0表示轻松背会，1表示费劲?*/
	write[0].open(filedir[1]), write[1].open(filedir[2]), write[2].open(filedir[3]), write[3].open(filedir[4]), write[4].open(filedir[5]), write[5].open(filedir[6], ios::app);
	resnum = 0;
	for (int i = 0; i<7; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j<store[i].size(); ++j)
			{
				if (res[resnum] == store[i][j].index)
				{
					++resnum;
				}
				store[i + 1].push_back(store[i][j]);
			}
		}
		else
		{
			for (int j = 0; j<store[i].size(); ++j)
			{
				if (resnum<res.size() && res[resnum] == store[i][j].index)
				{
					if (reciteres[resnum] == 0)
					{
						store[i][j].value = 1;
						store[i + 1].push_back(store[i][j]);
					}
					else
					{
						store[i][j].difficult++;
						store[i][j].value++;
						write[i - 1] << store[i][j].word1 << " " << store[i][j].value << " " << store[i][j].difficult << endl;
					}
					resnum++;
				}
				else
				{
					write[i - 1] << store[i][j].word1 << " " << store[i][j].value << " " << store[i][j].difficult << endl;
				}
			}
		}
	}
}

int main()
{
	cout << "请把想要背诵的单词写入new.txt，然后重启程序" << endl; 
	string filedir[7];
	filedir[0] = "new.txt";
	filedir[1] = "4.txt";
	filedir[2] = "5.txt";
	filedir[3] = "6.txt";
	filedir[4] = "7.txt";
	filedir[5] = "8.txt";
	filedir[6] = "already.txt";
	daypro(filedir);
	cout << "复习单词列表已更新，今日背诵结束" << endl;
	return 0;
}