#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<algorithm>
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::vector;
using std::max;
class changeMatrix
{
public:
    changeMatrix(istream &i,ostream &ou):in(i),out(ou){}
    void solve()
    {
        in>>line>>col>>time;
        for(int i=0;i<line;++i)
        {
            int nowconditinon=0,nowzeronum=0;
            vector<int> nowline;
            for(int j=0;j<col;++j)
            {
                int tmp;
                in>>tmp;
                nowconditinon<<=1;
                nowconditinon|=tmp;
                if(tmp==0)
                {
                    nowzeronum++;
                }
                nowline.push_back(tmp);
            }
            map.push_back(nowline);
            zeronum.push_back(nowzeronum);
            condition.push_back(nowconditinon);
        }
        int ans=0,anscondition=0;
        vector<int> candoline;
        bool isodd=time%2;
        for(int i=0;i<line;++i)
        {
            if(isodd)
            {
                if(zeronum[i]<=time&&zeronum[i]%2)
                {
                    candoline.push_back(i);
                }
            }
            else
            {
                if(zeronum[i]<=time&&zeronum[i]%2==0)
                {
                    candoline.push_back(i);
                }
            }
        }
        while(time>0)
        {
            int comb=(1<<time)-1;
            while(comb<1<<col)
            {
                int anstmp=0;
                for(int i=0;i<candoline.size();++i)
                {
                    int nowline=condition[candoline[i]]^comb;
                    if(nowline==(1<<col)-1)
                    {
                        anstmp++;
                    }
                }
                if(anstmp>ans)
                {
                    ans=anstmp;
                    anscondition=comb;
                }
                int x=comb&-comb,y=comb+x;
                comb=((comb&~y)/x>>1)|y;
            }
            time-=2;
        }
        if(time==0)
        {
            int anstmp=0;
            for(int i=0;i<line;++i)
            {
                if(zeronum[i]==0)
                {
                    anstmp++;
                }
            }
            if(anstmp>ans)
            {
                ans=anstmp;
                anscondition=0;
            }
        }
        out<<"The max possible number is "<<ans<<endl;
        out<<"To achieve this,need to change";
        int num=col,outcondition=anscondition;
        while(outcondition)
        {
            if(outcondition&1)
            {
                out<<" "<<num;
            }
            outcondition>>=1;
            num--;
        }
        out<<" row"<<endl;
    }
private:
    vector<vector<int>> map;
    vector<int> zeronum,condition;
    istream &in;
    ostream &out;
    int col,line,time;
};
int main()
{
    ifstream in("G:\\cs\\coding\\c++\\homework\\matrixinput.txt");
    ofstream out("G:\\cs\\coding\\c++\\homework\\matrixoutput.txt");
    changeMatrix ans(in,out);
    ans.solve();
    return 0;
}