#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxnode=9*9*4+10;
const int MAXN=9*9*9+10;
struct DLX      //矩阵的行和列是从1开始的  
{
	int n, m, size; //size为结点数  
	int U[maxnode], D[maxnode], L[maxnode], R[maxnode], Row[maxnode], Col[maxnode];
	int H[MAXN], S[MAXN];   //H为每一行的头结点，但不参与循环。S为每一列的结点个数  
	int ansd,ans[MAXN];

	void init(int _n, int _m)   //m为列  
	{
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++)   //初始化列的头结点  
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++) H[i] = -1;    //初始化行的头结点  
	}

	void Link(int r, int c)
	{
		size++; //类似于前向星  
		Col[size] = c;
		Row[size] = r;
		S[Col[size]]++;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] == -1) H[r] = L[size] = R[size] = size; //当前行为空  
		else        //当前行不为空： 头插法，无所谓顺序，因为Row、Col已经记录了位置  
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}

	void remove(int c)  //c是列的编号， 不是结点的编号  
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];     //在列的头结点的循环队列中， 越过列c  
		for (int i = D[c]; i != c; i = D[i])
			for (int j = R[i]; j != i; j = R[j])
			{
				//被删除结点的上下结点仍然有记录  
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				S[Col[j]]--;
			}
	}

	void resume(int c)
	{
		L[R[c]] = R[L[c]] = c;
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j])
			{
				U[D[j]] = D[U[j]] = j;
				S[Col[j]]++;
			}
	}

    bool Dance(int d)
    {
        if(R[0] == 0)return d <= ansd;
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c];i != c;i = D[i])
        {
            ans[d]=H[i];
            remove(i);
            for(int j = R[i];j != i;j = R[j])remove(j);
            if(Dance(d+1))return true;
            for(int j = L[i];j != i;j = L[j])resume(j);
            resume(i);
        }
        return false;
    }
};
DLX dlx;
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
string suka;
int main()
{
    while(cin>>suka)
    {
        if(suka=="end")
        {
            break;
        }
        dlx.init(9*9*9,9*9*4);
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                for(int v=0;v<9;++v)
                {
                    if(suka[i*9+j]=='.'||suka[i*9+j]=='1'+v)
                    {
                        dlx.Link(encode(i,j,v),encode(0,i,j));
                        dlx.Link(encode(i,j,v),encode(1,i,v));
                        dlx.Link(encode(i,j,v),encode(2,j,v));
                        dlx.Link(encode(i,j,v),encode(3,(i/3)*3+j/3,v));
                    }
                }
            }
        }
        dlx.ansd=81;
        dlx.Dance(0);
        for(int i=0;i<81;++i)
        {
            int r,c,v;
            decode(dlx.ans[i],r,c,v);
            suka[r*9+c]='1'+v;
        }
        cout<<suka<<endl;
    }
    return 0;
}