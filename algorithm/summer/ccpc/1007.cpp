#include<cstdio>
#include<algorithm>
using namespace std;
char mat[3050][3050];
int main()
{
    mat[0][0]='C',mat[0][1]='C',mat[1][0]='P',mat[1][1]='C';
    for(int i=1;i<=10;++i)
    {
        int rest=1<<i,toach=rest*2;
        for(int j=0;j<rest;++j)
        {
            for(int t=rest;t<toach;++t)
            {
                mat[j][t]=mat[j][t-rest];
            }
        }
        for(int j=rest;j<toach;++j)
        {
            for(int t=0;t<rest;++t)
            {
                if(mat[j-rest][t]=='C')
                {
                    mat[j][t]='P';
                }
                else
                {
                    mat[j][t]='C';
                }
            }
        }
        for(int j=rest;j<toach;++j)
        {
            for(int t=rest;t<toach;++t)
            {
                mat[j][t]=mat[j-rest][t-rest];
            }
        }
    }
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        int num;
        scanf("%d",&num);
        num=1<<num;
        for(int j=0;j<num;++j)
        {
            for(int t=0;t<num;++t)
            {
                printf("%c",mat[j][t]);
            }
            printf("\n");
        }
    }
    return 0;
}