#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp[100020];
int main()
{
    cout<<100000<<endl;
    int left=(0+100000)/2;
    int right=left+1,maxele=100000,minele=-100000;
    while(left>=0)
    {
        cmp[left]=maxele--;
        cmp[right]=minele++;
        if(left>0)
        {
            --left;
            ++right;
            cmp[left]=minele++;
            cmp[right]=maxele--;
        }
        --left,++right;
    }
    cout<<cmp[0];
    for(int i=1;i<100000;++i)
    {
        cout<<" "<<cmp[i];
    }
    cout<<endl;
    return 0;
}