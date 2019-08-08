//最小生成树做法
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#define CLR(x) memset(x,0,sizeof(x))
#define ll long long int
#define db double
using namespace std;
const int maxn=205;
int pre[maxn];
db cal[maxn][2];
int cas=1;
struct point
{
    int x,y;
    db dis;
}s[maxn*maxn];

void init()
{
    for(int i=0;i<maxn;i++)
        pre[i]=i;

}

int Find(int x)
{
    return pre[x]==x?x:pre[x]=Find(pre[x]);
}

void un(int x,int y)
{
    int m=Find(x);
    int n=Find(y);
    if(m!=n)
        pre[n]=m;
}

bool cmp(point a,point b)
{
    return a.dis<b.dis;
}

int main()
{
    int n;
    while(~scanf("%d",&n) && n){
        init();
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&cal[i][0],&cal[i][1]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                s[cnt].x=i;
                s[cnt].y=j;
                s[cnt].dis=sqrt(fabs(pow(cal[i][0]-cal[j][0],2)+pow(cal[i][1]-cal[j][1],2)));
                cnt++;
            }
        }
        sort(s,s+cnt,cmp);
        db m;
        for(int i=0;i<cnt;i++){
            m=s[i].dis;
            un(s[i].x,s[i].y);
            if(Find(pre[0])==Find(pre[1]))
                break;
        }
        printf("Scenario #%d\n",cas++);
        printf("Frog Distance = %.3f\n\n",m);
    }
}
