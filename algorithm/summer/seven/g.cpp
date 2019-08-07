#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<int, string> trans;
int finddig[40] = { 1000,900,800,700,600,500,400,300,200,100,90,80,70,60,50,40,30,20,10,9,8,7,6,5,4,3,2,1 };
void init()
{
	trans[1] = "I", trans[2] = "II", trans[3] = "III", trans[4] = "IV", trans[5] = "V", trans[6] = "VI", trans[7] = "VII", trans[8] = "VIII", trans[9] = "IX";
	trans[10] = "X", trans[20] = "XX", trans[30] = "XXX", trans[40] = "XL", trans[50] = "L", trans[60] = "LX", trans[70] = "LXX", trans[80] = "LXXX", trans[90] = "XC";
	trans[100] = "C", trans[200] = "CC", trans[300] = "CCC", trans[400] = "CD", trans[500] = "D", trans[600] = "DC", trans[700] = "DCC", trans[800] = "DCCC", trans[900] = "CM";
	trans[1000] = "M";
}
string translate(int n)
{
	string tmp;
	for (int i = 0; i < 28; ++i)
	{
		while (n >= finddig[i])
		{
			tmp += trans[finddig[i]];
			n -= finddig[i];
		}
		if (n == 0)
		{
			break;
		}
	}
	return tmp;
}
struct node
{
	string roman;
	int num;
};
bool cmp(node a, node b)
{
	return a.roman < b.roman;
}
node tocmp[1020];
int ran[1020];
int main()
{
	init();
	for (int i = 1; i <= 1000; ++i)
	{
		tocmp[i - 1].num = i;
		tocmp[i - 1].roman = translate(i);
	}
	sort(tocmp, tocmp + 1000, cmp);
	for (int i = 0; i < 1000; ++i)
	{
		ran[tocmp[i].num] = (i + 1);
	}
	int start = ran[1000], end = ran[38], len = end - start;
    for(int i=1;i<=1000;++i)
    {
        if(ran[i]>start)
        {
            ran[i]=(-1+ran[i]-start-len);
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int tmp,siz=0;
        scanf("%d",&tmp);
        int ans=0;
        if(tmp>1000)
        {
            siz=tmp/1000;
            tmp%=1000;
        }
        if(ran[tmp]<0)
        {
            ans=(len*-1*siz)+ran[tmp];
        }
        else
        {
            ans=siz*ran[1000]+ran[tmp];
        }
        printf("%d\n",ans);
    }
    return 0;
}
