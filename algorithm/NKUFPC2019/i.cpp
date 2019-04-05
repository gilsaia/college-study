#include<cstdio>
#include<algorithm>
using namespace std;
int matrix[220][220],truth[220][220];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int xnum=0;
    for(int i=0;i<n;++i)
    {
        bool havefind=false;
        for(int t=0;t<n;++t)
        {
            if(i==t)
            {
                continue;
            }
            bool lower=true;
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]<=matrix[t][j])
                {
                    continue;
                }
                lower=false;
                break;
            }
            if(lower)
            {
                havefind=true;
                break;
            }
        }
        if(n==1)
        {
            havefind=false;
        }
        if(havefind)
        {
            continue;
        }
        for(int j=0;j<m;++j)
        {
            truth[xnum][j]=matrix[i][j];
        }
        ++xnum;
    }
    int ynum=0;
    for(int i=0;i<m;++i)
    {
        bool havefind=false;
        for(int t=0;t<m;++t)
        {
            if(i==t)
            {
                continue;
            }
            bool lower=true;
            for(int j=0;j<xnum;++j)
            {
                if(truth[j][i]>=truth[j][t])
                {
                    continue;
                }
                lower=false;
                break;
            }
            if(lower)
            {
                havefind=true;
                break;
            }
        }
        if(m==1)
        {
            havefind=false;
        }
        if(havefind)
        {
            continue;
        }
        for(int j=0;j<xnum;++j)
        {
            matrix[j][ynum]=truth[j][i];
        }
        ++ynum;
    }
    double ans=0;
    for(int i=0;i<xnum;++i)
    {
        for(int j=i+1;j<xnum;++j)
        {
            for(int k=0;k<ynum;++k)
            {
                for(int t=k+1;t<ynum;++t)
                {
                    double x1,x2,y1,y2;
                    double y1tmp=matrix[j][t]-matrix[i][t],y2tmp=matrix[i][k]-matrix[j][k];
                    if(y1tmp==0&&y2tmp==0)
                    {
                        if(matrix[i][t]>matrix[i][k])
                        {
                            y2=0;
                            y1=1;
                        }
                        else
                        {
                            y1=0;
                            y2=1;
                        }
                    }
                    else
                    {
                        y1=y1tmp/(y1tmp+y2tmp);
                        y2=y2tmp/(y1tmp+y2tmp);
                        if(y1<0)
                        {
                            y1=0;
                            y2=1;
                        }
                        else if(y2<0)
                        {
                            y1=1;
                            y2=0;
                        }
                    }
                    double x1tmp=matrix[j][t]-matrix[j][k],x2tmp=matrix[i][k]-matrix[i][t];
                    if(x1tmp==0&&x2tmp==0)
                    {
                        if(matrix[j][k]>matrix[i][k])
                        {
                            x2=1;
                            x1=0;
                        }
                        else
                        {
                            x1=1;
                            x2=0;
                        }
                    }
                    else
                    {
                        x1=x1tmp/(x1tmp+x2tmp);
                        x2=x2tmp/(x1tmp+x2tmp);
                        if(x1<0)
                        {
                            x1=0;
                            x2=1;
                        }
                        else if(x2<0)
                        {
                            x2=0;
                            x1=0;
                        }
                    }
                    double c11=matrix[i][k],c12=matrix[i][t],c21=matrix[j][k],c22=matrix[j][t];
                    ans=max(ans,c11*x1*y1+c12*x1*y2+c21*x2*y1+c22*x2*y2);
                }
            }
        }
    }
    if(xnum==1)
    {
        for(int i=0;i<ynum;++i)
        {
            ans=max(ans,(double)matrix[0][i]);
        }
    }
    if(ynum==1)
    {
        for(int i=0;i<xnum;++i)
        {
            ans=max(ans,(double)matrix[i][0]);
        }
    }
    printf("%.6lf\n",ans);
    return 0;
}