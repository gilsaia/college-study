#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<utility>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int L, D;
	cin >> L >> D;
	stringstream strio;
	queue<pair<string, int>> que;
	int nowtime = 0;
	for (int i = 0; i < L; ++i)
	{
		vector<pair<string, int>> vec;
		strio.clear();
		string line;
		getline(cin, line);
		getline(cin, line);
		strio << line;
		string word;
		while (strio >> word)
		{
			int time;
			cin >> time;

			pair<string, int> tmp(word,nowtime);
			vec.push_back(tmp);
			tmp.second += D;
			que.push(tmp);
			nowtime += time;
		}
		string voice[2];
		int deltime = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			int nochange = 1;
			if ((vec[i].second+vec[i].first.size()) > que.front().second)
			{
				pair<string, int> sec = que.front();
				que.pop();
				int del = sec.second - vec[i].second;
				string ttt;
				for (int i = 0; i < deltime + del;++i)
				{
					ttt += '_';
				}
				sec.first = ttt + sec.first;
				voice[1] += sec.first;
				voice[1] += '_';
				int torec = sec.second + sec.first.size() - vec[i].second - vec[i].first.size()-deltime;
				torec = max(0, torec);
				for (int j = 0; j < torec; ++j)
				{
					vec[i].first += '_';
				}
				deltime = vec[i].second + vec[i].first.size() - sec.second - sec.first.size();
				deltime = max(0, deltime);
				nochange = 0;
			}
			voice[0] += vec[i].first;
			voice[0] += '_';
			if (nochange)
			{
				deltime += vec[i].first.size() + 1;
			}
		}
		voice[0].erase(voice[0].end() - 1);
		if (voice[1].empty())
		{
			voice[1] = "/";
		}
		else
		{
			voice[1].erase(voice[1].end() - 1);
		}
		cout << voice[0] << endl;
		cout << voice[1] << endl;
	}
	return 0;
}