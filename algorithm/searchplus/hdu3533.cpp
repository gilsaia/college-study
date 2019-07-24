#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
typedef pair<int, int> P;
bool bulletis[1021][105][105];
bool castleis[105][105];
bool visable[1021][105][105];
int m, n, k, d;
const int maxtime = 1020;
int dx[5] = { 1,0,0,-1,0 }, dy[5] = { 0,1,0,0,-1 };
struct bullcas
{
	int isbull;
	int dir, time, x, y;
	int per, vel;
	bool operator<(const bullcas& rhs) const
	{
		if (time == rhs.time)
		{
			return isbull < rhs.isbull;
		}
		return time > rhs.time;

	}
};
struct person
{
	int time, x, y;
	int h, f;
	int energy;
	bool operator<(const person& rhs) const
	{
		if (f == rhs.f)
		{
			return time > rhs.time;
		}
		return f > rhs.f;
	}
};
void geth(person& ps)
{
	ps.h = m - ps.x + n - ps.y;
	ps.f = ps.h + ps.time;
}
int main()
{
	while(cin >> m >> n >> k >> d)
    {
        memset(bulletis,false,sizeof(bulletis));
        memset(castleis,false,sizeof(castleis));
        memset(visable,false,sizeof(visable));
        priority_queue<bullcas> *que;
        que=new priority_queue<bullcas>;
        for (int i = 0; i < k; ++i)
        {
            char dir;
            int per, vel, x, y;
            cin >> dir >> per >> vel >> x >> y;
            P pos(x, y);
            castleis[x][y]=true;
            bullcas tmp;
            if (dir == 'N')
            {
                tmp.dir = 0;
            }
            else if (dir == 'E')
            {
                tmp.dir = 1;
            }
            else if (dir == 'S')
            {
                tmp.dir = 2;
            }
            else if (dir == 'W')
            {
                tmp.dir = 3;
            }
            tmp.isbull = 0;
            tmp.per = per;
            tmp.time = 0;
            tmp.x = x, tmp.y = y, tmp.vel = vel;
            que->push(tmp);
        }
        while (!que->empty())
        {
            bullcas tmp = que->top();
            que->pop();
            if (tmp.time > maxtime)
            {
                continue;
            }
            if (tmp.isbull == 0)
            {
                P pos(tmp.x, tmp.y);
                bullcas bull;
                bull.isbull = 1;
                bull.per = 1;
                bull.vel = tmp.vel;
                bull.time = tmp.time + 1;
                bull.dir = tmp.dir;
                if (tmp.dir == 0)
                {
                    pos.first -= tmp.vel;
                }
                else if (tmp.dir == 1)
                {
                    pos.second += tmp.vel;
                }
                else if (tmp.dir == 2)
                {
                    pos.first += tmp.vel;
                }
                else
                {
                    pos.second -= tmp.vel;
                }
                if (pos.first >= 0 && pos.first <= m && pos.second >= 0 && pos.second <= n)
                {
                    bull.x = pos.first, bull.y = pos.second;
                    que->push(bull);
                }
                tmp.time += tmp.per;
                que->push(tmp);
            }
            else
            {
                P pos(tmp.x, tmp.y);
                bulletis[tmp.time][tmp.x][tmp.y]=true;
                tmp.time += tmp.per;
                if (tmp.dir == 0)
                {
                    tmp.x -= tmp.vel;
                }
                else if (tmp.dir == 1)
                {
                    tmp.y += tmp.vel;
                }
                else if (tmp.dir == 2)
                {
                    tmp.x += tmp.vel;
                }
                else
                {
                    tmp.y -= tmp.vel;
                }
                if (tmp.x<0 || tmp.x>m || tmp.y<0 || tmp.y>n)
                {
                    continue;
                }
                if(castleis[tmp.x][tmp.y]==true)
                {
                    continue;
                }
                que->push(tmp);
            }
        }
        delete que;
        int ans = 0;
        priority_queue<person> bfs;
        person start;
        start.energy = d;
        start.time = 0;
        start.x = start.y = 0;
        geth(start);
        bfs.push(start);
        while (!bfs.empty())
        {
            person tmp = bfs.top();
            bfs.pop();
            if (tmp.x == m && tmp.y == n)
            {
                ans = tmp.time;
                break;
            }
            if (tmp.energy < 0)
            {
                continue;
            }
            for (int i = 0; i < 5; ++i)
            {
                person next = tmp;
                next.x += dx[i];
                next.y += dy[i];
                if (next.x<0 || next.x>m || next.y<0 || next.y>n)
                {
                    continue;
                }
                next.time++, next.energy--;
                if(castleis[next.x][next.y]==true)
                {
                    continue;
                }
                if(bulletis[next.time][next.x][next.y]==true)
                {
                    continue;
                }
                geth(next);
                if(next.h>next.energy)
                {
                    continue;
                }
                if(visable[next.time][next.x][next.y]==true)
                {
                    continue;
                }
                visable[next.time][next.x][next.y]=true;
                bfs.push(next);
            }
        }
        if (ans == 0)
        {
            cout << "Bad luck!" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

	return 0;
}