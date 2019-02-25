//年份问题···非常···牛逼··的·解法···
/*分析：2种操作，日+1，或月+1，（除了几个特殊日期外）均能改变月+日的奇偶性，
而目标11.4，月+日为奇数，所以只要起始日期的月+日为偶数,Adam,the first mover,就可能赢。而两个特殊日期（9.30，11.30），尽管月+日为奇数，但下一步仍然可以得到奇数。
*/
#include <iostream>
using namespace std;
 
bool win(int m,int d)
{
	if((m+d)%2==0)return true;
	if(d==30 && (m==9 ||m==11))return true;
	return false;
}
 
int main()
{
	int i,n;
	int y,m,d;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>y>>m>>d;
		if(win(m,d))cout<<"YES"<<endl;
		else  cout<<"NO"<<endl;
	}
	return 0;
}