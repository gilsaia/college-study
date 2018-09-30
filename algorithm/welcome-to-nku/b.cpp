#include<cstdio>
using namespace std;
int main()
{
    int n,k,biao=0;
    char in[60],chan[60];
    scanf("%d%d",&n,&k);
    scanf("%s",in);
    biao=n;
    for(int i=1;i<n;++i)
    {
        bool pan=0;
        for(int j=i;j<n;++j)
        {
            if(in[j]==in[j-i])
            {
                continue;
            }
            pan=1;
            break;
        }
        if(!pan)
        {
            biao=i;
            break;
        }
    }
    for(int i=0;i<biao;++i)
    {
        chan[i]=in[i];
    }
    chan[biao]='\0';
    for(int i=1;i<k;++i)
    {
        printf("%s",chan);
    }
    printf("%s\n",in);
    return 0;
}