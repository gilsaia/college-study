#include<cstdio>
#include<cstring>
#include<algorithm>
#define Bounds 500
using namespace std;
const int L[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int R[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MAXN = 1100;
struct Point {
    Point() {}
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    bool operator < (const Point& r)const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator == (const Point& r)const {
        return x == r.x && y == r.y;
    }
    bool operator != (const Point& r)const {
        return !(x == r.x && y == r.y);
    }
    int x, y;
} point[MAXN * MAXN], tmp[MAXN * MAXN * 8];
bool live[MAXN][MAXN];
int unique_point(int n) {
    int temp = 0, ret = 0;
    while (temp < n) {
        int cnt = 1;
        while (temp + cnt < n && tmp[temp] == tmp[temp + cnt]) cnt++;
        if (cnt < 2) {
            live[tmp[temp].x + Bounds][tmp[temp].y + Bounds] = false;
        } else if (cnt == 2) {
            if (live[tmp[temp].x + Bounds][tmp[temp].y + Bounds])
                point[ret++] = Point(tmp[temp].x, tmp[temp].y);
        } else if (cnt == 3) {
            live[tmp[temp].x + Bounds][tmp[temp].y + Bounds] = true;
            point[ret++] = Point(tmp[temp].x, tmp[temp].y);
        } else {
            live[tmp[temp].x + Bounds][tmp[temp].y + Bounds] = false;
        }
        temp += cnt;
    }
    return ret;
}
char line[20];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(live, false, sizeof(live));
        int n, m;
        scanf("%d%d", &n, &m);
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s",line);
            for(int j=0;line[j]!='\0';++j)
            {
                if(line[j]=='#')
                {
                    point[tot++] = Point(i, j);
                    live[i + Bounds][j + Bounds] = true;
                }
            }
        }
        int starttime = 0, maxpeople = tot;
        for (int i = 1; i <= 321; i++) {
            int sum = 0;
            for (int j = 0; j < tot; j++)
                for (int k = 0; k < 8; k++) {
                    int x = point[j].x + L[k];
                    int y = point[j].y + R[k];
                    tmp[sum++] = Point(x, y);
                }
            sort(tmp, tmp + sum);
            for (int j = 0; j < tot; j++) {
                if (*lower_bound(tmp, tmp + sum, point[j]) != point[j]) {
                    live[point[j].x + Bounds][point[j].y + Bounds] = false;
                }
            }
            tot = unique_point(sum);
            if (tot > maxpeople) {
                maxpeople = tot;
                starttime = i;
            }
            if (tot == 0) break;
        }
        printf("%d %d %d\n", starttime, maxpeople, tot);
    }
    return 0;
}