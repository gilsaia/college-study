#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int save[1200][1200];
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;++i)
    {
        memset(save,0,sizeof(save));
        string A,B;
        cin>>A>>B;
        int numa=A.length(),numb=B.length();
        for(int i=0;i<=numa;++i)
        {
            save[i][0]=i;
        }
        for(int i=0;i<=numb;++i)
        {
            save[0][i]=i;
        }
        for(int i=1;i<=numa;++i)
        {
            for(int j=1;j<=numb;++j)
            {
                int cmptmp;
                if(A[i-1]==B[j-1])
                {
                    cmptmp=save[i-1][j-1];
                }
                else
                {
                    cmptmp=save[i-1][j-1]+1;
                }
                save[i][j]=min(save[i-1][j]+1,min(save[i][j-1]+1,cmptmp));
            }
        }
        cout<<save[numa][numb]<<endl;
    }
    return 0;
}