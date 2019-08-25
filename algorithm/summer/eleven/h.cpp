#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int game[2][1020][1020];
const int BOUND=500;
char line[20];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
struct point
{
    int x;
    int y;
    point(int _x=0,int _y=0)
    {
        x=_x;
        y=_y;
    }
    bool operator<(const point &rhs) const
    {
        if(x!=rhs.x)
        {
            return y<rhs.y;
        }
        return x<rhs.x;
    }
    bool operator==(const point &rhs) const
    {
        return x==rhs.x&&y==rhs.y;
    }
};
point tosearch[1000020];
point life[2][1000020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        int maxlive=0,maxgen=0;
        scanf("%d%d",&n,&m);
        memset(game[0],0,sizeof(game[0]));
        for(int i=0;i<n;++i)
        {
            scanf("%s",line);
            for(int j=0;j<m;++j)
            {
                if(line[j]=='.')
                {
                    game[0][i][j]=0;
                }
                else
                {
                    game[0][i+BOUND][j+BOUND]=1;
                    life[0][maxlive]=point(i+BOUND,j+BOUND);
                    ++maxlive;
                }
            }
        }
        int nowlive=maxlive;
        for(int i=1;i<=321;++i)
        {
            int nowgenali=0;
            memset(game[i%2],0,sizeof(game[i%2]));
            int num=0;
            int end=0;
            for(int j=0;j<nowlive;++j)
            {
                for(int t=0;t<8;++t)
                {
                    int tx=life[(i+1)%2][j].x+dx[t],ty=life[(i+1)%2][j].y+dy[t];
                    if(tx<0||ty<0)
                    {
                        continue;
                    }
                    tosearch[num++]=point(tx,ty);
                }
                sort(tosearch,tosearch+num);
                end=unique(tosearch,tosearch+num)-tosearch;
            }
            for(int j=0;j<end;++j)
            {
                int isalive=0;
                for(int t=0;t<8;++t)
                {
                    int tx=tosearch[j].x+dx[t],ty=tosearch[j].y+dy[t];
                    if(tx<0||ty<0)
                    {
                        continue;
                    }
                    if(game[(i+1)%2][tx][ty]==1)
                    {
                        ++isalive;
                    }
                }
                if(isalive==3)
                {
                    point tmp=tosearch[j];
                    game[i%2][tmp.x][tmp.y]=1;
                    life[i%2][nowgenali]=tmp;
                    ++nowgenali;
                }
            }
            nowlive=nowgenali;
            if(nowgenali>maxlive)
            {
                maxlive=nowgenali;
                maxgen=i;
            }
            if(nowlive==0)
            {
                break;
            }
        }
        printf("%d %d %d\n",maxgen,maxlive,nowlive);
    }
    return 0;
}