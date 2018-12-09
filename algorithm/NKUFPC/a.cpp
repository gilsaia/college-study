#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct position
{
    int things,rightnum;
}save[12];
int main()
{
    char Te[50];
    //scanf("%s",Te);
    while(cin>>Te)
    {
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<10;++j)
            {
                char tmp[30];
                scanf("%s",tmp);
                getchar();
                if(j==1)
                {
                    if(tmp[6]=='@')
                    {
                        save[i].things=1;
                    }
                    else if(tmp[6]=='#')
                    {
                        save[i].things=0;
                    }
                    if(tmp[13]=='@')
                    {
                        save[i].things<<=1;
                        save[i].things|=1;
                    }
                    else if(tmp[13]=='#')
                    {
                        save[i].things<<=1;
                    }
                }
                else if(j==5)
                {
                    if(tmp[3]=='@')
                    {
                        save[i].things<<=1;
                        save[i].things|=1;
                    }
                    else if(tmp[3]=='#')
                    {
                        save[i].things<<=1;
                    }
                    if(tmp[17]=='@')
                    {
                        save[i].things<<=1;
                        save[i].things|=1;
                    }
                    else if(tmp[17]=='#')
                    {
                        save[i].things<<=1;
                    }
                }
                else if(j==8)
                {
                    if(tmp[6]=='@')
                    {
                        save[i].things<<=1;
                        save[i].things|=1;
                    }
                    else if(tmp[6]=='#')
                    {
                        save[i].things<<=1;
                    }
                    if(tmp[13]=='@')
                    {
                        save[i].things<<=1;
                        save[i].things|=1;
                    }
                    else if(tmp[13]=='#')
                    {
                        save[i].things<<=1;
                    }
                }
            }
            scanf("%d",&save[i].rightnum);
        }
        int ans=0;
        for(int i=0;i<=(1<<6)-1;++i)
        {
            bool pan=1;
            for(int j=0;j<10;++j)
            {
                int check=i^save[j].things,count=0;
                while(check!=0)
                {
                    check&=(check-1);
                    count++;
                }
                count=6-count;
                if(count!=save[j].rightnum)
                {
                    pan=0;
                    break;
                }
            }
            if(pan)
            {
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}