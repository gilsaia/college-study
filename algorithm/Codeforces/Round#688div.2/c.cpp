#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point{
    int x,y;
    point(int a,int b){
        x=a;
        y=b;
    }
};
bool cmp1(point a,point b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}
bool cmp2(point a,point b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    return a.y<b.y;
}
bool cmp3(point a,point b){
    if(a.x==b.x){
        return a.y>b.y;
    }
    return a.x<b.x;
}
bool cmp4(point a,point b){
    if(a.y==b.y){
        return a.x>b.x;
    }
    return a.y<b.y;
}
int res[10];
char str[2020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int tmp;
        vector<point> vec[10];
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%s",str);
            for(int j=0;j<n;++j){
                tmp=str[j]-'0';
                vec[tmp].push_back(point(i,j));
            }
        }
        for(int i=0;i<10;++i){
            res[i]=0;
            if(vec[i].size()<2){
                continue;
            }
            int len=vec[i].size();
            // for(int j=0;j<len;++j){
            //     for(int t=j+1;t<len;++t){
            //         int xl=min(vec[i][j].x,vec[i][t].x),xr=max(vec[i][j].x,vec[i][t].x),yl=min(vec[i][j].y,vec[i][t].y),yr=max(vec[i][j].y,vec[i][t].y);
            //         int wid=max(n-1-xl,xr),leng=max(n-1-yl,yr);
            //         res[i]=max(res[i],max((yr-yl)*wid,(xr-xl)*leng));
            //     }
            // }
            sort(vec[i].begin(),vec[i].end(),cmp1);
            vector<point> edge;
            int pos;
            edge.push_back(vec[i][0]);
            pos=1;
            while(pos<len&&vec[i][pos].x==vec[i][0].x){
                edge.push_back(vec[i][pos]);
                ++pos;
            }
            edge.push_back(vec[i][len-1]);
            pos=len-2;
            while(pos>=0&&vec[i][pos].x==vec[i][len-1].x){
                edge.push_back(vec[i][pos]);
                --pos;
            }
            sort(vec[i].begin(),vec[i].end(),cmp2);
            edge.push_back(vec[i][0]);
            pos=1;
            while(pos<len&&vec[i][pos].y==vec[i][0].y){
                edge.push_back(vec[i][pos]);
                ++pos;
            }
            edge.push_back(vec[i][len-1]);
            pos=len-2;
            while(pos>=0&&vec[i][pos].y==vec[i][len-1].y){
                edge.push_back(vec[i][pos]);
                --pos;
            }
            len=edge.size();
            for(int j=0;j<len;++j){
                for(int t=j+1;t<len;++t){
                    int xl=min(edge[j].x,edge[t].x),xr=max(edge[j].x,edge[t].x),yl=min(edge[j].y,edge[t].y),yr=max(edge[j].y,edge[t].y);
                    int wid=max(n-1-xl,xr),leng=max(n-1-yl,yr);
                    res[i]=max(res[i],max((yr-yl)*wid,(xr-xl)*leng));
                }
            }
            // res[i]=max((vec[i][len-1].y-vec[i][0].y)*max(n-1-min(vec[i][0].x,vec[i][len-1].x),max(vec[i][0].x,vec[i][len-1].x)),res[i]);
            // sort(vec[i].begin(),vec[i].end(),cmp3);
            // res[i]=(vec[i][len-1].x-vec[i][0].x)*max(n-1-min(vec[i][0].y,vec[i][len-1].y),max(vec[i][0].y,vec[i][len-1].y));
            // sort(vec[i].begin(),vec[i].end(),cmp4);
            // res[i]=max((vec[i][len-1].y-vec[i][0].y)*max(n-1-min(vec[i][0].x,vec[i][len-1].x),max(vec[i][0].x,vec[i][len-1].x)),res[i]);
        }
        printf("%d",res[0]);
        for(int i=1;i<10;++i){
            printf(" %d",res[i]);
        }
        printf("\n");
    }
    return 0;
}