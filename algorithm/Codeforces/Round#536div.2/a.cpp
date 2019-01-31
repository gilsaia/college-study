#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int Matrix[1020][1020];
int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            char tmp;
            cin>>tmp;
            if(tmp=='X')
            {
                if((i-1)>=0&&(j-1)>=0)
                {
                    Matrix[i-1][j-1]++;
                    if(Matrix[i-1][j-1]==5)
                    {
                        ++ans;
                    }
                }
                Matrix[i][j]++;
                if(Matrix[i][j]==5)
                {
                    ++ans;
                }
                if((i-1)>=0&&(j+1)<n)
                {
                    Matrix[i-1][j+1]++;
                    if(Matrix[i-1][j+1]==5)
                    {
                        ++ans;
                    }
                }
                if((i+1)<n&&(j-1)>=0)
                {
                    Matrix[i+1][j-1]++;
                    if(Matrix[i+1][j-1]==5)
                    {
                        ++ans;
                    }
                }
                if((i+1)<n&&(j+1)<n)
                {
                    Matrix[i+1][j+1]++;
                    if(Matrix[i+1][j+1]==5)
                    {
                        ++ans;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}