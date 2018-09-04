//坐标离散化的问题···看了题解思考了很长时间才大概搞懂含义···但是这个解法还是有一点存疑···另外似乎学了个新方法imos法···
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
int W,H,N;
int X1[1060],X2[1060],Y1[1060],Y2[1060];
int fld[1060*2][1060*2];
int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
const int MAXN=1060;
int compress(int *x1,int *x2,int w)
{
    vector<int> xs;
    for(int i=0;i<N;i++)
    {
        int tx1=x1[i],tx2=x2[i];
        if(tx1>0&&tx1<w)
        {
            xs.push_back(tx1);
        }
        if(tx2>0&&tx2<w)
        {
            xs.push_back(tx2);
        }
    }
    xs.push_back(0);
    xs.push_back(w);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    for(int i=0;i<N;i++)
    {
        x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin();
        x2[i]=find(xs.begin(),xs.end(),x2[i])-xs.begin();
    }
    return xs.size()-1;
}
int bfs()
{
    int ans=0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(fld[i][j])
            {
                continue;
            }
            ++ans;
            queue<pair<int,int>> que;
            que.push(make_pair(j,i));
            while(!que.empty())
            {
                int nx=que.front().first,ny=que.front().second;
                que.pop();
                for(int i=0;i<4;i++)
                {
                    int tx=nx+dx[i],ty=ny+dy[i];
                    if(tx<0||tx>W||ty<0||ty>H||fld[ty][tx]>0)
                    {
                        continue;
                    }
                    que.push(make_pair(tx,ty));
                    fld[ty][tx]=1;
                }
            }
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&W,&H),W&H)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
        }
        memset(fld,0,sizeof(fld));
        W=compress(X1,X2,W);
        H=compress(Y1,Y2,H);
        for(int i=0;i<N;i++)
        {
            fld[Y1[i]][X1[i]]++;
            fld[Y1[i]][X2[i]]--;
            fld[Y2[i]][X1[i]]--;
            fld[Y2[i]][X2[i]]++;
        }
        for(int i=0;i<H;i++)
        {
            for(int j=1;j<W;j++)
            {
                fld[i][j]+=fld[i][j-1];
            }
        }
        for(int i=1;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                fld[i][j]+=fld[i-1][j];
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}