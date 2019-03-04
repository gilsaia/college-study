#include<iostream>
#include<fstream>
using namespace std;
const int MAXN=40;
int man[MAXN][MAXN],woman[MAXN][MAXN];
int manchoose[MAXN],womanchoose[MAXN];
int res[MAXN];
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
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>man[i][j];
            man[i][j]--;
        }
        womanchoose[i]=-1;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int pos;
            cin>>pos;
            woman[i][--pos]=j;
        }
    }
    for(int i=0;i<n;++i)
    {
        gs(i,n,0);
    }
    for(int i=0;i<n;++i)
    {
        res[womanchoose[i]]=i;
    }
    for(int i=0;i<n;++i)
    {
        cout<<++res[i]<<" ";
    }
    cout<<endl;
    return 0;
}