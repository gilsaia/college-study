#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using std::pair;
using std::make_pair;
using std::vector;
template <typename Save>
class hophash
{
    public:
    hophash(size_t prime=13,size_t DIST=4):size(prime),used(0),MAX_DIST(DIST)
    {
        database.resize(prime);
    }
    bool insert(Save x)
    {
        size_t num=hash(x);
        size_t caninsert=num,opnum=0;
        do
        {
            if(posempty(caninsert))
            {
                break;
            }
            else
            {
                opnum++;
                caninsert=(caninsert+1)%size;
            }
        }
        while(caninsert!=num)
        if(opnum<MAX_DIST)
        {
            database[caninsert].first=x;
            database[num].second|=(1<<(MAX_DIST-1-opnum));
        }
        else if(caninsert!=num)
        {
            while(opnum>=MAX_DIST)
            {
                if(trytomove(caninsert))
                {
                    opnum=(caninsert+size-num)%size;
                }
                else
                {
                    return false;
                }
            }
            database[caninsert].first=x;
            database[num].second|=(1<<(MAX_DIST-1-opnum));
        }
        else
        {
            return false;
        }
        return true;
    }
    bool search(Save x)
    {
        size_t num=hash(x);
        size_t move=0;
        while(move<MAX_DIST)
        {
            if(database[num].second>>(MAX_DIST-1-move)&1==1&&database[(num+move)%size].first==x)
            {
                return true;
            }
            ++move;
        }
        return false;
    }
    private:
    size_t size;
    size_t used;
    size_t MAX_DIST;
    vector<pair<Save,int>> database;
    size_t hash(Save x);
    bool posempty(size_t num)
    {
        size_t thelast=(num-MAX_DIST+1+size)%size;
        size_t move=0;
        while(move<MAX_DIST)
        {
            if(thelast&1<<move==1)
            {
                return false;
            }
            move++;
            thelast=(thelast+1)%size;
        }
        return true;
    }
    bool trytomove(size_t &nowpos)
    {
        size_t thelast=(nowpos-MAX_DIST+1+size)%size;
        size_t move=0;
        while(move<MAX_DIST)
        {
            if(database[thelast].second>0)
            {
                size_t tochange=MAX_DIST-1;
                while(database[thelast].second>>tochange&1==0)
                {
                    tochange--;
                }
                database[nowpos].first=database[(thelast+MAX_DIST-tochange-1)%size].first;
                database[thelast].second&=!(1<<tochange)
                database[thelast].second&=1<<move;
                nowpos=thelast;
                return true;
            }
            else
            {
                move++;
                thelast=(thelast+1)%size;
            }
        }
        return false;
    }
};