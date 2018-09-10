//运行时间O(N)
#include<vector>
#include<iostream>
using namespace std;
template <typename object>
void printLots(vector<object> L,vector<int> P)
{
    for(int i=0;i<P.size();i++)
    {
        cout<<L[P[i]];
    }
}