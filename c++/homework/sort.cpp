#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;
using std::sort;
using std::endl;
using std::setw;
using std::pow;
const int size=10000;
const int ENDL=20;
class testsort
{
public:
    testsort(ostream &ou=cout,istream &i=cin):out(ou),in(i){}
    void initial()
    {
        int tmp;
        for(int i=0;i<size;++i)
        {
            in>>tmp;
            source.push_back(tmp);
        }
        vector<int> res(source);
        sort(res.begin(),res.end());
        print(res);
    }
    void insertsort()
    {
        int cmpnum=0,changenum=0;
        vector<int> touse(source);
        for(int i=1;i<size;++i)
        {
            int tmp=touse[i];
            changenum++;
            int j=i;
            for(;j>0;--j)
            {
                ++cmpnum;
                if(touse[j-1]>tmp)
                {
                    touse[j]=touse[j-1],++changenum;
                }
                else
                {
                    break;
                }
            }
            touse[j]=tmp,++changenum;
        }
        //print(touse);
        out<<"Insertsort:"<<endl;
        out<<"Compare number is "<<cmpnum<<endl<<"Change number is "<<changenum<<endl;
    }
    void Selectsort()
    {
        int cmpnum=0,changenum=0;
        vector<int> touse(source);
        for(int i=0;i<size;++i)
        {
            int num=i;
            for(int j=i;j<size;++j)
            {
                ++cmpnum;
                if(touse[j]<touse[num])
                {
                    num=j;
                }
            }
            int tmp=touse[num];
            touse[num]=touse[i];
            touse[i]=tmp;
            changenum+=3;
        }
        //print(touse);
        out<<"Selectsort:"<<endl;
        out<<"Compare number is "<<cmpnum<<endl<<"Change number is "<<changenum<<endl;
    }
    void Shellsort()
    {
        int cmpnum=0,changenum=0;
        vector<int> touse(source);
        vector<int> gap(buildincreasesuquence());
        for(int i=gap.size()-1;i>=0;--i)
        {
            for(int j=i;j<size;++j)
            {
                int tmp=touse[j];
                changenum++;
                int t=j;
                for(;t>=i;t-=i)
                {
                    cmpnum++;
                    if(tmp<touse[t-i])
                    {
                        touse[t]=touse[t-i],changenum++;
                    }
                    else
                    {
                        break;
                    }
                }
                touse[t]=tmp,changenum++;
            }
        }
        //print(touse);
        out<<"Shellsort:"<<endl;
        out<<"Compare number is "<<cmpnum<<endl<<"Change number is "<<changenum<<endl;
    }
    void Mergesort()
    {
        int cmpnum=0,changenum=0;
        vector<int> touse(source);
        vector<int> tmp(touse.size());
        Mergesort(touse,tmp,0,size-1,cmpnum,changenum);
        //print(touse);
        out<<"Mergesort:"<<endl;
        out<<"Compare number is "<<cmpnum<<endl<<"Change number is "<<changenum<<endl;
    }
    void Quicksort()
    {
        int cmpnum=0,changenum=0;
        vector<int> touse(source);
        Quicksort(touse,0,size-1,cmpnum,changenum);
        //print(touse);
        out<<"Quicksort:"<<endl;
        out<<"Compare number is "<<cmpnum<<endl<<"Change number is "<<changenum<<endl;
    }
    void print(vector<int> &toout)
    {
        out<<"The right order is:"<<endl;
        for(int i=0;i<size;)
        {
            out<<setw(6)<<toout[i];
            if(++i%ENDL==0)
            {
                out<<endl;
            }
            else
            {
                out<<" ";
            }
        }
    }
    void solve()
    {
        initial();
        insertsort();
        Selectsort();
        Shellsort();
        Mergesort();
        Quicksort();
    }
private:
    ostream &out;
    istream &in;
    vector<int> source;
    vector<int> buildincreasesuquence()
    {
        int startup1=0,startup2=2,tmp=0,i=0;
        vector<int> res;
        while(tmp<size)
        {
            if(i%2)
            {
                tmp=pow(4,startup2)-3*pow(2,startup2)+1;
                startup2++;
                res.push_back(tmp);
            }
            else
            {
                tmp=9*pow(4,startup1)-9*pow(2,startup1)+1;
                startup1++;
                res.push_back(tmp);
            }
        }
        return res;
    }
    void Mergesort(vector<int> &touse,vector<int> &tmp,int left,int right,int &cmpnum,int &changenum)
    {
        if(left<right)
        {
            int center=(left+right)/2;
            Mergesort(touse,tmp,left,center,cmpnum,changenum);
            Mergesort(touse,tmp,center+1,right,cmpnum,changenum);
            merge(touse,tmp,left,center+1,right,cmpnum,changenum);
        }
    }
    void merge(vector<int> &touse,vector<int> &tmp,int left,int right,int rend,int &cmpnum,int &changenum)
    {
        int lend=right-1;
        int nowpos=left;
        int elements=rend-left+1;
        while(left<=lend&&right<=rend)
        {
            cmpnum++;
            if(touse[left]<=touse[right])
            {
                tmp[nowpos++]=touse[left++];
                changenum++;
            }
            else
            {
                tmp[nowpos++]=touse[right++];
                changenum++;
            }
        }
        while(left<=lend)
        {
            tmp[nowpos++]=touse[left++];
            changenum++;
        }
        while(right<=rend)
        {
            tmp[nowpos++]=touse[right++];
            changenum++;
        }
        for(int i=0;i<elements;++i,--rend)
        {
            touse[rend]=tmp[rend];
            changenum++;
        }
    }
    int &findmeter(vector<int> &touse,int left,int right,int &cmpnum,int &changenum)
    {
        int center=(left+right)/2;
        cmpnum+=3;
        if(touse[center]<touse[left])
        {
            std::swap(touse[left],touse[center]);
            changenum+=3;
        }
        if(touse[right]<touse[left])
        {
            std::swap(touse[right],touse[left]);
            changenum+=3;
        }
        if(touse[right]<touse[center])
        {
            std::swap(touse[right],touse[center]);
            changenum+=3;
        }
        std::swap(touse[center],touse[right-1]);
        changenum+=3;
        return touse[right-1];
    }
    void Quicksort(vector<int> &touse,int left,int right,int &cmpnum,int &changenum)
    {
        if(left+10<=right)
        {
            int &sign=(findmeter(touse,left,right,cmpnum,changenum));
            int i=left,j=right-1;
            while(1)
            {
                cmpnum++;
                while(touse[++i]<sign)
                {
                    cmpnum++;
                }
                cmpnum++;
                while(sign<touse[--j])
                {
                    cmpnum++;
                }
                if(i<j)
                {
                    std::swap(touse[i],touse[j]);
                    changenum+=3;
                }
                else
                {
                    break;
                }
            }
            std::swap(touse[i],touse[right-1]);
            Quicksort(touse,left,i-1,cmpnum,changenum);
            Quicksort(touse,i+1,right,cmpnum,changenum);
        }
        else
        {
            for(int i=left+1;i<=right;++i)
            {
                int tmp=touse[i];
                changenum++;
                int j=i;
                for(;j>left;--j)
                {
                    ++cmpnum;
                    if(touse[j-1]>tmp)
                    {
                        touse[j]=touse[j-1],++changenum;
                    }
                    else
                    {
                        break;
                    }
                }
                touse[j]=tmp,++changenum;
            }
        }
    }
};
int main()
{
    ifstream in("G:\\cs\\coding\\c++\\homework\\randnumber.txt");
    ofstream out("G:\\cs\\coding\\c++\\homework\\sortoutput.txt");
    testsort ans(out,in);
    ans.solve();
    return 0;
}