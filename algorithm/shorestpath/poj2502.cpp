#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int N = 209;
const int MAX = 0x3f3f3f3f;
int dx[N], dy[N];
double v[N][N];
bool vis[N];
double dis[N];

double dijkstra(int n)
{
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<n; i++)
        dis[i] = v[0][i];
    dis[0] = 0;
    vis[0] = 1;
    for(int i=1; i<n; i++)
    {
        int x = -1;
        double max = MAX;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && dis[j] < max)
                max = dis[x = j];
        }
        if(x == -1)
            break;
        vis[x] = 1;
        for(int j=0; j<n; j++)
            if(!vis[j] && dis[j] > max + v[x][j])
                dis[j] = max + v[x][j];
    }
    return dis[1];
}

int main()
{
    scanf("%d%d%d%d", &dx[0], &dy[0], &dx[1], &dy[1]);
    int t, pos;
    t = pos = 2;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            v[i][j] = MAX;
    while(~scanf("%d%d", &dx[pos], &dy[pos]))
    {
        pos++;
        while(~scanf("%d%d", &dx[pos], &dy[pos]) && dx[pos] != -1 && dy[pos] != -1)
        {
            v[pos-1][pos] = v[pos][pos-1] =
                60*sqrt((dx[pos]-dx[pos-1])*(dx[pos]-dx[pos-1])
                +(dy[pos]-dy[pos-1])*(dy[pos]-dy[pos-1]))/40000.0;
            pos++;
        }
    }
    for(int i=0; i<pos; i++)
    {
        for(int j=i+1; j<pos; j++)
            v[i][j] = v[j][i] =
                min(v[i][j],
                    60*sqrt((dx[i]-dx[j])*(dx[i]-dx[j])
                            +(dy[i]-dy[j])*(dy[i]-dy[j]))/10000.0);
    }
    printf("%.0f\n", dijkstra(pos));
    return 0;
}