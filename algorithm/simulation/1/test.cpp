#include<cstdio>
using namespace std;
int main()
{
    int num[100];
    num[0]=0,num[1]=0;
    for(int i=2;i<100;++i)
    {
        num[i]=num[i-1]+num[i-2]*2+i+1;
        printf("%d\n",num[i]);
    }
    return 0;
}