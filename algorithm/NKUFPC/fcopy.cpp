#include <iostream>
using namespace std;
typedef long long ll;
const ll p=1000000007;
ll in(ll t, ll p) 
{
    return t == 1 ? 1 : (p - p / t) * in(p % t, p) % p;
}
int main(){
	int t;
	ll n;
	scanf("%d",&t);
	ll r6=in(6,p),r4=in(4,p);
	while(t--){
		scanf("%lld",&n);
		n--;
		int tmp=n%p;
		tmp=(tmp*(n+1))%p;
		tmp=(tmp*(n+1))%p;
		tmp=(tmp*(2*n+1))%p;
		tmp=(tmp*r6)%p;
		if(tmp<0) tmp+=p;
		int tmp2=n%p;
		tmp2=(tmp2*n)%p;
		tmp2=(tmp2*(n+1))%p;
		tmp2=(tmp2*(n+1))%p;
		tmp2=(tmp2*r4)%p;
		tmp=tmp-tmp2;
		if(tmp<0) tmp+=p;
		printf("%d\n",tmp%p);
	}
	return 0;
}
