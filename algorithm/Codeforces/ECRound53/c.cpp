#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF=1e9;
int sum[210050];
int main()
{
    int n,x,y,posx=0,posy=0;
    scanf("%d",&n);
    string opera;
    cin>>opera;
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;++i)
    {
        switch(opera[i])
        {
            case 'U':
            ++posy;
            break;
            case 'D':
            --posy;
            break;
            case 'L':
            --posx;
            break;
            case 'R':
            ++posx;
            break;
        }
    }
    int disx=x-posx,disy=y-posy;
    if((disx+disy)%2!=0)
    {
        printf("-1\n");
        return 0;
    }
    char opex='a',opey='a';
    if(disx<0)
    {
        opex='R';
    }
    else if(disx>0)
    {
        opex='L';
    }
    if(disy<0)
    {
        opey='U';
    }
    else if(disy>0)
    {
        opey='D';
    }
    int num=(abs(disx)+abs(disy))/2,ans=INF;
    if(num==0)
    {
        ans=0;
    }
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1];
        if(opera[i-1]==opex||opera[i-1]==opey)
        {
            sum[i]++;
        }
    }
    int s=0,t=0,anstmp=0;
    while(t<=n)
    {
        anstmp=sum[t]-sum[s];
        if(anstmp<num)
        {
            ++t;
        }
        else if(anstmp>num)
        {
            ++s;
        }
        else
        {
            ans=min(ans,t-s);
            ++s;
        }
        if(s>t)
        {
            ++t;
        }
    }
    /*for(int i=0;i<n;++i)
    {
        int numtmp=0;
        for(int j=i;j<n;++j)
        {   
            if(opera[j]==opex||opera[j]==opey)
            {
                ++numtmp;
            } 
            if(numtmp==num)
            {
                ans=min(ans,j-i+1);
                break;
            } 
        }
    }*/
    if(ans==INF)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",ans);
    }
    return 0;
}