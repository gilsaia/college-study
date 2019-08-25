#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int sequ[10][10];
int lengt[10];
struct node
{
    int h;
    int seqpoint[10];
    node()
    {
        h=0;
        for(int i=0;i<10;++i)
        {
            seqpoint[i]=0;
        }
    }
};
int n;
int dfs(node tmp,int step,int leng)
{
    if(step==leng)
    {
        if(tmp.h==0)
        {
            return 1;
        }
        return 0;
    }
    int count[5];
    for(int i=0;i<5;++i)
    {
        count[i]=0;
    }
    int check=0;
    for(int i=0;i<n;++i)
    {
        ++count[sequ[i][tmp.seqpoint[i]+1]];
        check=max(check,lengt[i]-tmp.seqpoint[i]);
    }
    if(leng-step<check)
    {
        return 0;
    }
    int ans=0;
    for(int i=1;i<5;++i)
    {
        node next=tmp;
        if(count[i]!=0)
        {
            for(int j=0;j<n;++j)
            {
                if(sequ[j][tmp.seqpoint[j]+1]==i)
                {
                    ++next.seqpoint[j];
                }
            }
            next.h-=count[i];
            ans=max(dfs(next,step+1,leng),ans);
        }
    }
    return ans;
}
int sum;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            string tmp;
            cin>>tmp;
            for(int j=0;j<tmp.size();++j)
            {
                if(tmp[j]=='A')
                {
                    sequ[i][j+1]=1;
                }
                else if(tmp[j]=='C')
                {
                    sequ[i][j+1]=2;
                }
                else if(tmp[j]=='G')
                {
                    sequ[i][j+1]=3;
                }
                else
                {
                    sequ[i][j+1]=4;
                }
            }
            sequ[i][tmp.size()+1]=0;
            lengt[i]=tmp.size();
            sum+=tmp.size();
        }
        for(int i=1;i<=40;++i)
        {
            node start;
            start.h=sum;
            if(dfs(start,0,i))
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}