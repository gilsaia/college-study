#include<algorithm>
#include<iostream>
using std::min;
const int MAXN=1e6;
const int INF=1e9+7;//不能存在总长度大于INF的路径，但INF开到更大不合适，因为int的最大值为2*1e9，如果再大两个INF相加是可能会爆int导致出现负数
int map[MAXN][MAXN];//已存好的图路径(注意无向图是对称的），自己对自己的值为0，不存在边的值为无穷！！！
int tc[MAXN][MAXN];//结果数组
void undirectedTC(int n)
{
    for(int k=0;k<n;++k)//floyd算法的思想，三重循环
    {
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(i!=k&&j!=k)
                {
                    if((map[i][k]+map[k][j])<INF)
                    {
                        tc[i][j]=1;
                    }
                    map[i][j]=map[j][i]=min(map[i][j],map[i][k]+map[k][j]);
                }
            }
        }
    }
}