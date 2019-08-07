#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int rannum[1200];
int step[1200];
int nowste[40];
int main()
{
    int p;
    scanf("%d",&p);
    for(int i=0;i<p;++i)
    {
        scanf("%d",&rannum[i]);
        step[nowste[rannum[i]]]=i;
        nowste[rannum[i]]=i;
    }
    int find=0,findi,findn,findm;
    for(int i=0;i<p;++i)
    {
        for(int n=1;(i+n)<p;++n)
        {
            for(int m=1;(i+n+m)<p;++m)
            {
                int a=rannum[i],b=rannum[i+n],c=rannum[i+n+m];
                int num=1,now=i;
                int need=p/40+1;
                if(p%40)
                {
                    ++need;
                }
                while(step[now]!=0)
                {
                    int tmp=step[now];
                    if((tmp+n)<p&&(tmp+n+m)<p&&rannum[tmp+n]==b&&rannum[tmp+n+m]==c&&(tmp)!=(i)&&(tmp+n)!=(i)&&(tmp+n+m)!=(i)&&(tmp)!=(i+n)&&(tmp+n)!=(i+n)&&(tmp+n+m)!=(i+n)&&(tmp)!=(i+n+m)&&(tmp+n)!=(i+n+m)&&(tmp+n+m)!=(i+n+m))
                    {
                        ++num;
                    }
                    now=step[now];
                }
                if(num>=need)
                {
                    find=1;
                    findi=i,findn=n,findm=m;
                    break;
                }
                num=1,now=i+n;
                while(step[now]!=0)
                {
                    int tmp=step[now];
                    if((tmp-n)>=0&&(tmp+m)<p&&rannum[tmp-n]==a&&rannum[tmp+m]==c&&(tmp-n)!=(i)&&(tmp)!=(i)&&(tmp+m)!=(i)&&(tmp-n)!=(i+n)&&(tmp)!=(i+n)&&(tmp+m)!=(i+n)&&(tmp-n)!=(i+n+m)&&(tmp)!=(i+n+m)&&(tmp+m)!=(i+n+m))
                    {
                        ++num;
                    }
                    now=step[now];
                }
                if(num>=need)
                {
                    find=1;
                    findi=i,findn=n,findm=m;
                    break;
                }
                num=1,now=i+n+m;
                while(step[now]!=0)
                {
                    int tmp=step[now];
                    if((tmp-n-m)>=0&&(tmp-m)>=0&&rannum[tmp-n-m]==a&&rannum[tmp-m]==b&&(tmp-n-m)!=(i)&&(tmp-m)!=(i)&&(tmp)!=(i)&&(tmp-n-m)!=(i+n)&&(tmp-m)!=(i+n)&&(tmp)!=(i+n)&&(tmp-n-m)!=(i+n+m)&&(tmp-m)!=(i+n+m)&&(tmp)!=(i+n+m))
                    {
                        ++num;
                    }
                    now=step[now];
                }
                if(num>=need)
                {
                    find=1;
                    findi=i,findn=n,findm=m;                    
                    break;
                }
            }
            if(find==1)
            {
                break;
            }
        }
        if(find==1)
        {
            break;
        }
    }
    if(find)
    {
        printf("triple correlation %d(%d)%d(%d)%d found\n",rannum[findi],findn,rannum[findi+findn],findm,rannum[findi+findn+findm]);
    }
    else
    {
        printf("random sequence\n");
    }
    return 0;
}