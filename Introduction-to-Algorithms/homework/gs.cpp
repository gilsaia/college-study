#include<iostream>
#include<fstream>
using namespace std;
const int MAXN=1e3;
int man[MAXN][MAXN],woman[MAXN][MAXN];
int manchoose[MAXN],womanchoose[MAXN];
void gs(int num,int &sum,int pos)
{
    for(int i=pos;i<sum;++i)
    {
        int wonum=man[num][i];
        if(womanchoose[wonum]==-1)
        {
            manchoose[num]=i;
            womanchoose[wonum]=num;
            break;
        }
        int oldmannum=womanchoose[wonum];
        if(woman[wonum][oldmannum]>woman[wonum][num])
        {
            manchoose[num]=i;
            womanchoose[wonum]=num;
            gs(oldmannum,sum,manchoose[oldmannum]);
            break;
        }
    }
    return;
}
int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n;
    in>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            in>>man[i][j];
        }
        womanchoose[i]=-1;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int pos;
            in>>pos;
            woman[i][pos]=j;
        }
    }
    for(int i=0;i<n;++i)
    {
        gs(i,n,0);
    }
    for(int i=0;i<n;++i)
    {
        out<<womanchoose[i]<<" "<<i<<endl;
    }
    return 0;
}