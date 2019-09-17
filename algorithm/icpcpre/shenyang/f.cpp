#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    multiset<int> pl;
	int n,k;
while(~scanf("%d%d",&n,&k))
{
    pl.clear();	
	for(int i=0;i<n;i++)
    {
		int tmp;
		scanf("%d",&tmp);
		pl.insert(tmp);
	 } 
	 
	//multiset<int>::iterator iter1;  
    //for(iter1 =pool.begin(); iter1 !=pool.end(); iter1++)   
    //cout<<*iter1<<"  ";
	//cout<<endl;
	 
	 for(int i=1;i<=k;i++){
	 	 multiset<int>::iterator iter=pool.end();
		 iter--;  
	 	 int temp1=*iter;
	 	 pool.erase(iter);
		 pool.insert(--temp1);
    //multiset<int>::iterator iter2;  
    //for(iter2 =pool.begin(); iter2 !=pool.end(); iter2++)   
    //cout<<*iter2<<"  ";
	//cout<<endl;
	 	 
	 	
	 	 int temp2=*pool.begin();
	 	 pool.erase(pool.begin());
		 pool.insert(++temp2);
	//multiset<int>::iterator iter3;  
    //for(iter3 =pool.begin(); iter3 !=pool.end(); iter3++)   
    //cout<<*iter3<<"  ";
	//cout<<endl;
	 }
	 cout<<*pool.rbegin()-*pool.begin()<<endl;
   }
	return 0;
 } 