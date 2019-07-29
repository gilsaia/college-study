#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int save[120][120];
int rawshow[120][120];
int rawcount[120];
int n;
set<int> col[120],raw[120];
int dfs(int rawi, int coli)
{
    for(auto i=col[coli].begin();i!=col[coli].end();++i)
    {
        if(raw[rawi].find(*i)==raw[rawi].end())
        {
            return 0;
        }
        save[rawi][coli]=*i;
        raw[rawi].erase(*i);
        if(coli==n-1)
        {
            col[coli].erase(*i);
            return 1;
        }
        if(dfs(rawi,coli+1))
        {
            col[coli].erase(*i);
            return 1;
        }
        raw[rawi].insert(*i);
    }
    return 0;
}
int main()
{
	int k;
	scanf("%d%d", &n, &k);
	bool can = true;
    set<int> trytmp;
    for(int i=1;i<=n;++i)
    {
        trytmp.insert(i);
    }
    for(int i=0;i<n;++i)
    {
        col[i]=trytmp;
        raw[i]=trytmp;
    }
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &save[i][j]);
            if(raw[i].find(save[i][j])==raw[i].end()||col[j].find(save[i][j])==col[j].end())
            {
                can=false;
            }
            raw[i].erase(save[i][j]);
            col[j].erase(save[i][j]);
		}
	}
	if (can == false)
	{
		printf("no\n");
		return 0;
	}
	printf("yes\n");
	if (k < n)
	{
		for (int i = k; i < n; ++i)
		{
			dfs(i, n);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d", save[i][j]);
			if (j != n - 1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
	return 0;
}