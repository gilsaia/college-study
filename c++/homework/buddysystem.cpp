//开始数字代表内存总大小
//之后第一个数字代表操作类型
//0为索取空间，之后为空间对应标号和空间大小
//1为归还空间，之后为空间对应标号
//2为显示当前剩余空间状态
//-1为结束程序
#ifndef BUDDYSYSTEM_H
#define BUDDYSYSTEM_H
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
#include<map>
#include<iomanip>
using ll=long long;
using std::pair;
using std::make_pair;
using std::cout;
using std::cin;
using std::ostream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::map;
using std::endl;
using std::setw;
using std::left;
using std::right;
struct node
{
    ll address,size;
    node *next;
    node(ll add=0,ll sizet=1024,node *n=nullptr):address(add),next(n)
    {
        ll modsize=1;
        while(modsize<sizet)
        {
            modsize<<=1;
        }
        size=modsize;
    }
    bool operator<(const node &rhs)
    {
        if(size==rhs.size)
        {
            return address<rhs.address;
        }
        return size>rhs.size;
    }
};
class buddysystem
{
    public:
    void print(ostream& output)
    {
        output<<left<<setw(12)<<"address"<<setw(12)<<"size"<<endl<<right;
        if(head==nullptr)
        {
            return;
        }
        node *curr=head;
        output<<left<<setw(12)<<curr->address<<setw(12)<<curr->size<<endl<<right;
        while(curr!=tail)
        {
            curr=curr->next;            
            output<<left<<setw(12)<<curr->address<<setw(12)<<curr->size<<endl<<right;
        }
    }
    buddysystem(ostream& wrong=cout):wrongout(wrong)
    {
        tail=head=new node();
    }
    buddysystem(ll size,ostream& wrong=cout):wrongout(wrong)
    {
        tail=head=new node(0,size);
    }
    bool request(ll num,ll size)
    {
        if(used.find(num)!=used.end())
        {
            wrongout<<"wrong request!"<<endl;
            return false;
        }
        ll sizet=1;
        while(sizet<size)
        {
            sizet<<=1;
        }
        node *curr=head;
        while(curr!=tail&&curr->next->size>=sizet)
        {
            curr=curr->next;
        }
        if(curr->size==sizet)
        {
            used[num]=make_pair(curr->address,sizet);
            erase(curr->address,curr->size);
            return true;
        }
        if(curr->size<sizet)
        {
            wrongout<<"memory limit exceed!"<<endl;
            return false;
        }
        ll addresstmp=curr->address,sizetmp=curr->size;
        while(sizetmp>sizet)
        {
            erase(addresstmp,sizetmp);
            insert(addresstmp,sizetmp/2);
            curr=insert(addresstmp+sizetmp/2,sizetmp/2);
            addresstmp=addresstmp+sizetmp/2;
            sizetmp/=2;
        }
        used[num]=make_pair(addresstmp,sizetmp);
        erase(addresstmp,sizetmp);
        return true;
    }
    bool realease(ll num)
    {
        if(used.find(num)==used.end())
        {
            wrongout<<"doesn't exist!"<<endl;
            return false;
        }
        ll addressrea=used[num].first,sizerea=used[num].second;
        ll addresstmp=0,sizetmp=0;
        used.erase(num);
        node *curr=insert(addressrea,sizerea),*find=head;
        while(find!=curr)
        {
            if(curr->next!=nullptr&&curr->next->size==curr->size&&curr->next->address==curr->address+curr->size)
            {
                addresstmp=curr->address,sizetmp=curr->size;
                erase(addresstmp,sizetmp);
                erase(addresstmp+sizetmp,sizetmp);
                curr=insert(addresstmp,sizetmp*2);
                continue;
            }
            if(find->next==curr&&find->size==curr->size&&find->address+find->size==curr->address)
            {
                addresstmp=find->address,sizetmp=find->size;
                erase(addresstmp,sizetmp);
                erase(addresstmp+sizetmp,sizetmp);
                curr=insert(addresstmp,sizetmp*2);
                find=head;
                continue;
            }
            find=find->next;
        }
        return true;
    }
    private:
    node *insert(ll address,ll size)
    {
        if(head!=nullptr)
        {
            node *ine=new node(address,size),*find=head;
            if(*ine<*head)
            {
                ine->next=head;
                head=ine;
                return head;
            }
            else
            {
                while(find->next!=nullptr&&(*(find->next)<*ine))
                {
                    find=find->next;
                }
                ine->next=find->next;
                find->next=ine;
                if(ine->next==nullptr)
                {
                    tail=ine;
                }
                return ine;
            }
        }
        else
        {
            head=tail=new node(address,size);
            return head;
        }
    }
    node *erase(ll address,ll size)
    {
        if(head!=nullptr)
        {
            if(head->address==address&&head->size==size)
            {
                node *oldnode=head;
                head=head->next;
                if(head==nullptr)
                {
                    tail=nullptr;
                }
                delete oldnode;
                return head;
            }
            else
            {
                node *find=head;
                while(find->next!=nullptr&&!(find->next->address==address&&find->next->size==size))
                {
                    find=find->next;
                }
                node *oldnode=find->next;
                if(oldnode==nullptr)
                {
                    return nullptr;
                }
                find->next=find->next->next;
                delete oldnode;
                if(find->next==nullptr)
                {
                    tail=find;
                }
                return find;
            }
        }
        else
        {
            return nullptr;
        }
    }
    node *head,*tail;
    map<ll,pair<ll,ll>> used;
    ostream& wrongout;
};
int main()
{
    ll totalsize;
	ifstream input("G:\\cs\\coding\\c++\\homework\\buddysystemin.txt");
	ofstream output("G:\\cs\\coding\\c++\\homework\\buddysystemout.txt");
    input>>totalsize;
    buddysystem memory(totalsize,output);
    int operationnum;
    while(input>>operationnum)
    {
        if(operationnum==-1)
        {
            break;
        }
        ll num,size;
        switch(operationnum)
        {
            case 0:
            input>>num>>size;
            memory.request(num,size);
            break;
            case 1:
            input>>num;
            memory.realease(num);
            break;
            case 2:
            memory.print(output);
            break;
            default:
            break;
        }
    }
    return 0;
}
#endif