#include<fstream>
#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll listsize=5e5;
const ll total=1e9;
int main()
{
    ofstream out("G:\\cs\\coding\\algorithm\\NKUFPC\\list.txt");
    ll res=1;
    for(ll i=0;i<=total;++i)
    {
        if(i%listsize==0)
        {
            out<<res<<",";
        }
        res=res*(i+1)%MOD;
    }
    return 0;
}