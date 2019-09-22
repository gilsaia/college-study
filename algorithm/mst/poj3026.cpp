#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int N = 109;
const int MAX = 1000000;
int g[N][N];
int d[N];
char s[59][59];
int qx[] = {-1, 1, 0, 0};
int qy[] = {0, 0, 1, -1};
bool vist[59][59];

struct Node
{
    int x, y, num;
}spot[N];

int find(int x, int y, int len)
{
    for(int i=0;i<len;i++)
        if(spot[i].x == x && spot[i].y == y)
            return i;
    return -1;
}

void bfs(int pos, int x, int y, int xlen, int ylen, int plen)
{
    queue<Node> q;
    spot[pos].num = 0;
    q.push(spot[pos]);
    vist[x][y] = 1;
    while(!q.empty())
    {
        Node t = q.front();
        q.pop();
        if(s[t.x][t.y] == 'A' || s[t.x][t.y] == 'S')
        {
            int tpos = find(t.x, t.y, plen);
            g[pos][tpos] = g[tpos][pos] = t.num;
        }

        int dx, dy;
        for(int i=0;i<4;i++)
        {
            dx = qx[i] + t.x;
            dy = qy[i] + t.y;
            if(dx>=0 && dx<xlen && dy>=0 && dy<ylen
               && !vist[dx][dy] && s[dx][dy]!='#')
            {
                Node p = {dx, dy, t.num+1};
                q.push(p);
                vist[dx][dy] = 1;
            }
        }
    }
}

int prim(int n)
{
    for(int i=0;i<n;i++)
        d[i] = g[0][i];
    d[0] = -1;

    int ans = 0;

    for(int i=1;i<n;i++)
    {
        int min = MAX;
        int imin = -1;
        for(int j=0;j<n;j++)
            if(d[j]!=-1 && min > d[j])
                min = d[j], imin = j;

        ans += min;
        d[imin] = -1;
        for(int j=0;j<n;j++)
            if(d[j]!=-1 && d[j] > g[imin][j])
                d[j] = g[imin][j];
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int y, x;
        int num = 0;
        scanf("%d%d", &y, &x);
        gets(s[0]);
        for(int i=0;i<x;i++)
            gets(s[i]);
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
                if(s[i][j] == 'A' || s[i][j] == 'S')
                    spot[num++] = {i, j};
        }

        for(int i=0;i<num;i++)
        {
            memset(vist, 0, sizeof(vist));
            s[spot[i].x][spot[i].y] = ' ';
            bfs(i, spot[i].x, spot[i].y, x, y, num);
        }
        printf("%d\n",prim(num));
    }
    return 0;
}