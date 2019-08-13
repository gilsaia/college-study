#include<cstdio>
#include<algorithm>
using namespace std;
char save[50020][12];
int main()
{
    int r,c;
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)
    {
        scanf("%s",save[i]);
    }
    for(int i=0;i<c;++i)
    {
        int j=0,num=0,start=0;
        while(j<r)
        {
            if(save[j][i]=='a')
            {
                ++num;
            }
            else if(save[j][i]=='#')
            {
                for(int t=1;t<=num;++t)
                {
                    save[j-t][i]='a';
                }
                for(int t=j-num-1;t>=start;--t)
                {
                    save[t][i]='.';
                }
                start=j+1;
                num=0;
            }
            ++j;
        }
        for(int t=1;t<=num;++t)
        {
            save[j-t][i]='a';
        }
        for(int t=j-num-1;t>=start;--t)
        {
            save[t][i]='.';
        }
    }
    for(int i=0;i<r;++i)
    {
        printf("%s\n",save[i]);
    }
    return 0;
}