#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
struct position
{
    int things[10],rightnum;
}save[12];
int rightsize[10];
vector<int> cmp(position a,position b)
{
    vector<int> ans;
    for(int i=0;i<6;++i)
    {
        if(rightsize[i]==0&&a.things[i]!=b.things[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    string T;
    char Te[50];
    while(scanf("%s",Te))
    {
        getchar();
        for(int i=0;i<6;++i)
        {
            rightsize[i]=0;
        }
        int surenum=0;
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
                        save[i].things[0]=2;
                    }
                    else if(tmp[6]=='#')
                    {
                        save[i].things[0]=1;
                    }
                    if(tmp[13]=='@')
                    {
                        save[i].things[1]=2;
                    }
                    else if(tmp[13]=='#')
                    {
                        save[i].things[1]=1;
                    }
                }
                else if(j==5)
                {
                    if(tmp[3]=='@')
                    {
                        save[i].things[2]=2;
                    }
                    else if(tmp[3]=='#')
                    {
                        save[i].things[2]=1;
                    }
                    if(tmp[17]=='@')
                    {
                        save[i].things[3]=2;
                    }
                    else if(tmp[17]=='#')
                    {
                        save[i].things[3]=1;
                    }
                }
                else if(j==8)
                {
                    if(tmp[6]=='@')
                    {
                        save[i].things[4]=2;
                    }
                    else if(tmp[6]=='#')
                    {
                        save[i].things[4]=1;
                    }
                    if(tmp[13]=='@')
                    {
                        save[i].things[5]=2;
                    }
                    else if(tmp[13]=='#')
                    {
                        save[i].things[5]=1;
                    }
                }
            }
            scanf("%d",&save[i].rightnum);
            if(save[i].rightnum==6)
            {
                surenum=6;
            }
        }
        if(surenum==6)
        {
            printf("%d\n",1);
            continue;
        }
        int nowright=0;
        do{
            surenum=nowright;
            for(int i=0;i<10;++i)
            {
                if(6-nowright==save[i].rightnum)
                {
                    surenum=6;
                    nowright=6;
                    break;
                }
                for(int j=i+1;j<10;++j)
                {
                    vector<int> dif=cmp(save[i],save[j]);
                    if(dif.size()==abs(save[i].rightnum-save[j].rightnum))
                    {
                        if(save[i].rightnum>save[j].rightnum)
                        {
                            for(int t=0;t<dif.size();++t)
                            {
                                rightsize[dif[t]]=save[i].things[dif[t]];
                                for(int m=0;m<10;++m)
                                {
                                    if(save[m].things[dif[t]]==rightsize[dif[t]])
                                    {
                                        save[m].rightnum--;
                                    }
                                }
                            }
                        }
                        else if(save[i].rightnum<save[j].rightnum)
                        {
                            for(int t=0;t<dif.size();++t)
                            {
                                rightsize[dif[t]]=save[j].things[dif[t]];
                                for(int m=0;m<10;++m)
                                {
                                    if(save[m].things[dif[t]]==rightsize[dif[t]])
                                    {
                                        save[m].rightnum--;
                                    }
                                }
                            }
                        }
                        nowright+=dif.size();
                    }
                    if(6-nowright==save[j].rightnum)
                    {
                        surenum=6;
                        nowright=6;
                        break;
                    }
                }
            }
        }while(nowright!=surenum);
        int ans=1,topow=6-surenum;
        while(topow>0)
        {
            ans<<=1;
            topow--;
        }
        printf("%d\n",ans);
    }
    return 0;
}