#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxc=1200;
const int maxnode=1200;
const int maxr=1200;

struct DLX
{
    int n,sz;//列数，结点数
    int S[maxc];//各列结点数
    int row[maxnode],col[maxnode];//各点行列编号
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];//十字链表
    int ansd,ans[maxr];//解
 
    void init(int n)
    {
        this->n=n;
 
        //虚拟结点
        for (int i=0;i<=n;i++)
        {
            U[i]=i;D[i]=i;L[i]=i-1;R[i]=i+1;
        }
 
        R[n]=0;L[0]=n;
        sz=n+1;
        memset(S,0,sizeof S);
    }
 
    //插入决策行  _r 行号  columns 记录结点列号·[1,n]
    void add_row(int _r,vector<int> columns)
    {
        int first=sz;
        for (int i=0;i<columns.size();i++)
        {
            int _c=columns[i];
            L[sz]=sz-1;R[sz]=sz+1;
            D[sz]=_c;U[sz]=U[_c];//成环
            D[U[_c]]=sz;U[_c]=sz;
            row[sz]=_r;col[sz]=_c;
            S[_c]++;sz++;
        }
        R[sz-1]=first;L[first]=sz-1;
    }
 
    //删除一列结点
    void _remove(int _c)
    {
        L[R[_c]]=L[_c];
        R[L[_c]]=R[_c];
 
        for (int i=D[_c];i!=_c;i=D[i])
            for (int j=R[i];j!=i;j=R[j])
            {
                U[D[j]]=U[j];D[U[j]]=D[j];S[col[j]]--;
            }
    }
 
    //恢复一列结点，和删除顺序相反
    void _resume(int _c)
    {
        for (int i=U[_c];i!=_c;i=U[i])
            for (int j=L[i];j!=i;j=L[j])
            {
                U[D[j]]=j;D[U[j]]=j;S[col[j]]++;
            }
 
        L[R[_c]]=_c;
        R[L[_c]]=_c;
    }
 
    bool dfs(int d)
    {
        if (R[0]==0)
        {
            ansd=max(ansd,d); //记录解的长度
            return true;
        }
 
        //找最少结点的列删除
        int _c=R[0];
        for (int i=R[0];i!=0;i=R[i])
            if (S[i]<S[_c]) _c=i;
 
        _remove(_c);
        for (int i=D[_c];i!=_c;i=D[i])
        {
            ans[d]=row[i];
            for (int j=R[i];j!=i;j=R[j])
                _remove(col[j]);
 
            dfs(d+1);
 
            for (int j=L[i];j!=i;j=L[j])//反向恢复
                _resume(col[j]);
        }
        _resume(_c);
 
        return false;
    }
 
    bool solve(vector<int> &v)
    {
        v.clear();
        if (!dfs(0)) return false;
 
        for (int i=0;i<ansd;i++)    v.push_back(ans[i]);
 
        return true;
    }
 
}solver;
ll number[1200];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&number[i]);
        }
        solver.init(n);
        for(int i=1;i<=n;++i)
        {
            vector<int> col;
            for(int j=1;j<=n;++j)
            {
                if(j%i==0)
                {
                    col.push_back(j);
                }
            }
            solver.add_row(i,col);
        }
        vector<int> ans;
        solver.solve(ans);
        solver.ansd=0;
        printf("%d\n",solver.ansd);
    }
    return 0;
}