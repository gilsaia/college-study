#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
/* 
–A----C-----O-I
-J–A-B-P-CGF-H-
–D--F-I-E----P-
-G-EL-H----M-J–
----E----C–G—
-I–K-GA-B—E-J
D-GP–J-F----A–
-E—C-B–DP–O-
E–F-M–D--L-K-A
-C--------O-I-L-
H-P-C–F-A–B—
—G-OD—J----H
K—J----H-A-P-L
–B--P–E--K–A-
-H–B--K–FI-C–
–F—C–D--H-N-
*/
const int maxc=9*9*4+10;
const int maxnode=9*9*9*4+10;
const int maxr=9*9*9+10;

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
            ansd=d; //记录解的长度
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
 
            if (dfs(d+1))   return true;
 
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
 
int encode(int a,int b,int c)
{
    return a*81+b*9+c+1;
}
 
void decode(int code,int &a,int &b,int &c)
{
    code--;
 
    c=code%9; code/=9;
    b=code%9; code/=9;
    a=code;
}
string sudoku;
int main()
{
    while (cin>>sudoku)
    {
        if(sudoku=="end")
        {
            break;
        }
        solver.init(9*9*4);

        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                for (int v=0;v<9;v++)
                {
                    if (sudoku[i*9+j]=='.' || sudoku[i*9+j]=='1'+v)
                    {
                        vector<int> columns;
                        columns.push_back(encode(0,i,j));//i行j列要有数字
                        columns.push_back(encode(1,i,v));//i行要有数字v
                        columns.push_back(encode(2,j,v));//j列要有数字v
                        columns.push_back(encode(3,(i/3)*3+j/3,v));//第(i/3)*3+j/3个方块要有数字v
                        solver.add_row(encode(i,j,v),columns);
                    }
                } 
            }
        }
        vector<int> ans;
        solver.solve(ans); 
        for (int i=0;i<ans.size();i++)
        {
            int r,c,v;
            decode(ans[i],r,c,v);
            sudoku[r*9+c]='1'+v;
        }
        cout<<sudoku<<endl;
    }
    return 0;
}