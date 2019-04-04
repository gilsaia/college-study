#include<complex>
#include<iostream>
#include<algorithm>
using namespace std;
const double pai=3.1415926;
double save[1050];
complex<double> tocal[1050];
int main()
{
    int sum,f;
    cin>>sum>>f;
    for(int i=0;i<sum;++i)
    {
        cin>>save[i];
    }
    int num=sum/f;
    for(int i=0;i<num;++i)
    {
        for(int j=0;j<f;++j)
        {
            for(int t=0;t<f;++t)
            {
                tocal[t]+=complex<double>(save[i*f+j]*cos(j*t*2*pai/f),-save[i*f+j]*sin(j*t*2*pai/f));
            }
        }
        int ans=0;
        double tmp=0;
        for(int j=0;j<f;++j)
        {
            if(abs(tocal[j])>tmp)
            {
                tmp=abs(tocal[j]);
                ans=j;
            }
            tocal[j]=complex<double>(0,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}