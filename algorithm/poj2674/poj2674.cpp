//弹性碰撞的题···异常坑爹···没仔细读题的锅···思路好说··我的想法是找到最长的时间然后算出各自位置排好序找离两端最近的那个···要注意的地方···一个是它是要截断而不是四舍五入···还有一个方向注意是大小写都有的···
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
double pos[32010];
char name[32010][260];
double L,V,posi[32010];
char dir[32010];
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        scanf("%lf%lf",&L,&V);
        for(int i=0;i<n;i++)
        {
            cin>>dir[i]>>posi[i]>>name[i];
        }
        double time=0;
        for(int i=0;i<n;i++)
        {
            if(dir[i]=='p'||dir[i]=='P')
            {
                double s=L-posi[i];
                time=max(time,s/V);
            }
            else
            {
                time=max(time,posi[i]/V);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dir[i]=='p'||dir[i]=='P')
            {
                pos[i]=posi[i]+time*V;
            }
            else
            {
                pos[i]=posi[i]-time*V;
            }
        }
        sort(pos,pos+n);
        int ans=0;
        double mins=1e8;
        for(int i=0;i<n;i++)
        {
            if(abs(pos[i]-L)<abs(pos[i]))
            {
                double tmp=pos[i]-L;
                if(tmp<mins)
                {
                    mins=tmp;
                    ans=i;
                }
            }
            else
            {
                double tmp=0-pos[i];
                if(tmp<mins)
                {
                    mins=tmp;
                    ans=i;
                }
            }
        }
        printf("%13.2lf ",(int)(time * 100) / 100.0);
        cout<<name[ans]<<endl;
    }
    return 0;
}