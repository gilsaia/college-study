#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<ios>
using std::vector;
using std::lower_bound;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::min;
using std::max;
using std::string;
using std::ios;
using std::sort;
const int N=100;
const int D=1e4;
struct word
{
    int index,difficult,value;
    string word;
};
vector<int> torecite(vector<int> &S,vector<int> &d,vector<int> &v)
{
    vector<int> findpath[N+1][D];
    int dp[N+1][D];
    for(int i=0;i<=N;++i)
    {
        for(int j=0;j<D;++j)
        {
            dp[i][j]=0;
        }
    }
    for(int i=0;i<S.size();++i)
    {
        for(int j=min(i+1,N);j>0;--j)
        {
            for(int t=D-1;t>=d[i];--t)
            {
                if((dp[j-1][t-d[i]]+v[i])>dp[j][t])
                {
                    dp[j][t]=dp[j-1][t-d[i]]+v[i];
                    findpath[j][t].push_back(i);
                }
            }
        }
    }
    int ssize=S.size();
    int num=min(ssize,N);
    vector<int> index;
    int maxnum=S.size()+1,nowdifficult=D-1;
    for(int i=0;i<num;++i)
    {
        auto tofind=lower_bound(findpath[num-i][nowdifficult].begin(),findpath[num-i][nowdifficult].end(),maxnum);
        --tofind;
        int tmp=*tofind;
        index.push_back(S[*tofind]);
        maxnum=tmp+1,nowdifficult-=d[tmp];
    }
    return index;
}
const int circle[6]={0,1,2,4,7,15};
const int cirvalue[6]={1,1,1,1,1,1};
const int mustrecite=20;
void daypro(string filedir[7])
{
    ifstream read1(filedir[0]),read2(filedir[1]),read3(filedir[2]),read4(filedir[3]),read5(filedir[4]),read6(filedir[5]);
    ofstream write[6];
    write[0].open(filedir[1]),write[1].open(filedir[2]),write[2].open(filedir[3]),write[3].open(filedir[4]),write[4].open(filedir[5]),write[5].open(filedir[6],ios::app);
    vector<word> store[7];
    int index=0;
    word tmp;
    while(read1>>tmp.word)
    {
        read1>>tmp.difficult;
        tmp.value=1;
        tmp.index=index++;
        store[0].push_back(tmp);
    }
    /*以此类推读入六个文件的单词(注意除了第一个表其他表默认所有单词都有价值需要读入)*/
    vector<int> S,d,v,beforerecite;
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<store[i].size();++j)
        {
            if(store[i][j].value<circle[i])
            {
                ++store[i][j].value;
            }
            else if(store[i][j].difficult>=mustrecite)
            {
                beforerecite.push_back(store[i][j].index);
            }
            else
            {
                S.push_back(store[i][j].index);
                d.push_back(store[i][j].difficult);
                v.push_back(store[i][j].value*cirvalue[i]);
            }
        }
    }
    vector<int> res;
    res=torecite(S,d,v);
    for(int i=0;i<beforerecite.size();++i)
    {
        res.push_back(beforerecite[i]);
    }
    sort(res.begin(),res.end());
    vector<string> list;
    int resnum=0;
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<store[i].size();++j)
        {
            if(resnum<res.size())
            {
                if(res[resnum]==store[i][j].index)
                {
                    list.push_back(store[i][j].word);
                    resnum++;
                }
            }
            else
            {
                break;
            }
        }
    }
    vector<int> reciteres;
    /*list即为背诵单词表，在这里进行交互操作来获得背诵情况
    这里假设reciteres得到的为对应单词的背诵结果，0表示轻松背会，1表示费劲*/
    resnum=0;
    for(int i=0;i<7;++i)
    {
        if(i==0)
        {
            for(int j=0;j<store[i].size();++j)
            {
                if(res[resnum]==store[i][j].index)
                {
                    ++resnum;
                }
                store[i+1].push_back(store[i][j]);
            }
        }
        else
        {
            for(int j=0;j<store[i].size();++j)
            {
                if(resnum<res.size()&&res[resnum]==store[i][j].index)
                {
                    if(reciteres[resnum]==0)
                    {
                        store[i][j].value=1;
                        store[i+1].push_back(store[i][j]);
                    }
                    else
                    {
                        store[i][j].difficult++;
                        store[i][j].value++;
                        write[i-1]<<store[i][j].word<<" "<<store[i][j].value<<" "<<store[i][j].difficult<<endl;
                    }
                    resnum++;
                }
                else
                {
                    write[i-1]<<store[i][j].word<<" "<<store[i][j].value<<" "<<store[i][j].difficult<<endl;
                }
            }
        }
    }
}
