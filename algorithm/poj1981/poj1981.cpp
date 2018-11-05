#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double EPS=1e-6;
int N;
double X[320],Y[320];
double dist(int i,int j)
{
    return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}
void getmid(int i,int j,double &cenx,double &ceny)
{
    double midx,midy;
    midx=(X[i]+X[j])/2.0,midy=(Y[i]+Y[j])/2.0;
    double angal=atan2(X[i]-X[j],Y[j]-Y[i]);
    double dcm=sqrt(1.0-(X[i]-midx)*(X[i]-midx)-(Y[i]-midy)*(Y[i]-midy));
    cenx=midx+dcm*cos(angal),ceny=midy+dcm*sin(angal);
}
int main()
{
    while(scanf("%d",&N),N)
    {
        for(int i=0;i<N;++i)
        {
            scanf("%lf%lf",&X[i],&Y[i]);
        }
        int ans=1;
        for(int i=0;i<N;++i)
        {
            for(int j=i+1;j<N;++j)
            {
                if(dist(i,j)>2.0)
                {
                    continue;
                }
                double midx,midy;
                getmid(i,j,midx,midy);
                int cnt=0;
                for(int k=0;k<N;++k)
                {
                    if(sqrt((X[k]-midx)*(X[k]-midx)+(Y[k]-midy)*(Y[k]-midy))<1.0+EPS)
                    {
                        ++cnt;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}