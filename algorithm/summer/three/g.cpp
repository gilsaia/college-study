#include<cstdio>
#include<string>
using namespace std;
int order[200020];
int main()
{
	int n;
	string ope;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i < n; ++i)
	{
		char tmp;
		scanf("%c", &tmp);
		ope += tmp;
	}
	int nowstep = 1, nowhave = 0, nowpoint = 0;
	for (int i = 0; i < ope.size(); ++i)
	{
		if (ope[i] == 'L')
		{
			++nowhave, ++nowstep;
		}
		else
		{
			for (int j = 0; j <= nowhave; ++j)
			{
				order[nowpoint] = nowstep - j;
				++nowpoint;
			}
			nowhave = 0;
			++nowstep;
		}
	}
	for (int j = 0; j <= nowhave; ++j)
	{
		order[nowpoint] = nowstep - j;
		++nowpoint;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", order[i]);
	}
	return 0;
}