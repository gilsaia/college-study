//实际输入多项式每一项皆以0,0结尾,+,-,*,%,/分别在最后按照0,1,2,3,4顺序对应
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using std::vector;
using std::sort;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::pair;
using std::swap;
using std::make_pair;
using std::ostream;
using std::endl;
using std::cin;
using std::cout;
template <typename comparable>
struct link//节点的结构
{
	comparable coefficient, index;
	link *next;
	link(comparable coe = comparable(0), comparable ind = comparable(0), link *n = nullptr) :coefficient(coe), index(ind), next(n) {}
	bool operator<(const link &camp)//以便实现排序
	{
		if (index == camp.index)
		{
			return coefficient>camp.coefficient;
		}
		return index>camp.index;
	}
};
template <typename comparable>
class calculator//实现多项式计算具体的类
{
public:
	void insert(int coefficient,int index)
	{
		link<comparable> *input=new link<comparable>(coefficient,index),*cur=root;
		while(cur->next->next!=nullptr)
		{
			cur=cur->next;
		}
		input->next=cur->next;
		cur->next=input;
	}
	void print(ostream &os)//打印出当前的多项式
	{
		link<comparable> *toout = root;
		while (toout->next != nullptr)
		{
			if (toout->coefficient >= 0)
			{
				os << "+";
			}
			os << toout->coefficient << "x" << "^" << toout->index << " ";
			toout = toout->next;
		}
		os << endl;
	}
	calculator()//默认构造函数
	{
		root = new link<comparable>();
		root->coefficient = (comparable)0;
		root->index = (comparable)0;
		root->next = nullptr;
	}
	calculator(vector<link<comparable>> &organ)//对于输入的构造函数同时进行了排序
	{
		//sort(organ.begin(), organ.end());
		link<comparable> *update=nullptr,*last=nullptr;
		for (int i = 0; i < organ.size(); ++i)
		{
			link<comparable> *tmp = new link<comparable>();
			tmp->coefficient = organ[i].coefficient;
			tmp->index = organ[i].index;
			tmp->next = nullptr;
			if (i != 0)
			{
				last->next = tmp;
				last = tmp;
			}
			else
			{
				last = tmp;
				update = tmp;
			}
		}
		root = update;
	}
	calculator(const calculator &rhs)//拷贝构造函数
	{
		link<comparable> *copy=nullptr,*last=nullptr;
		link<comparable> *torhs = rhs.root;
		int flag = 0;
		while (torhs != nullptr)
		{
			link<comparable> *tmp = new link<comparable>();
			tmp->coefficient = torhs->coefficient;
			tmp->index = torhs->index;
			tmp->next = nullptr;
			if (flag!=0)
			{
				last->next = tmp;
			}
			else
			{
				copy = tmp;
			}
			last = tmp;
			flag = 1;
			torhs = torhs->next;
		}
		root = copy;
	}
	calculator(link<comparable>* t)//对已连成链表节点的构造函数
	{
		root = t;
	}
	~calculator()//析构函数
	{
		link<comparable> *theold = root;
		if (root != nullptr)
		{
			link<comparable>*todel = root->next;
			while (todel != nullptr)
			{
				delete theold;
				theold = todel;
				todel = todel->next;
			}
		}
	}
	calculator &operator=(const calculator &rhs)//重载赋值号
	{
		calculator copy(rhs);
		swap(this->root, copy.root);
		return *this;
	}
	const calculator operator-() const//重载负号
	{
		link<comparable> *cur = root;
		while (cur != nullptr)
		{
			cur->coefficient = -cur->coefficient;
			cur = cur->next;
		}
		return *this;
	}
	calculator operator+(const calculator &rhs) //重载加号
	{
		link<comparable> *torhs = rhs.root, *tolhs = root;
		link<comparable> *result, *cur;
		result = new link<comparable>();
		cur = result;
		while (!(torhs == nullptr&&tolhs == nullptr))//对两侧相加不同情况的判断
		{
			if (torhs == nullptr)
			{
				if (tolhs->coefficient == 0 && tolhs->index != 0)//若该项系数为0则忽略（下同）
				{
					tolhs = tolhs->next;
					continue;
				}
				cur->index = tolhs->index;
				cur->coefficient = tolhs->coefficient;
				if (!(cur->coefficient == (comparable)0 && cur->index == (comparable)0))//若不为最后一项则建立新的节点
				{
					link<comparable> *tmp;
					tmp = new link<comparable>();
					cur->next = tmp;
					cur = tmp;
				}
				tolhs = tolhs->next;
			}
			else if (tolhs == nullptr)
			{
				if (torhs->coefficient == 0 && torhs->index != 0)
				{
					torhs = torhs->next;
					continue;
				}
				cur->index = torhs->index;
				cur->coefficient = torhs->coefficient;
				if (!(cur->coefficient == (comparable)0 && cur->index == (comparable)0))
				{
					link<comparable> *tmp;
					tmp = new link<comparable>();
					cur->next = tmp;
					cur = tmp;
				}
				torhs = torhs->next;
			}
			else
			{
				if (torhs->index>tolhs->index)
				{
					if (torhs->coefficient == 0 && torhs->index != 0)
					{
						torhs = torhs->next;
						continue;
					}
					cur->index = torhs->index;
					cur->coefficient = torhs->coefficient;
					link<comparable> *tmp;
					tmp = new link<comparable>();
					cur->next = tmp;
					cur = tmp;
					torhs = torhs->next;
				}
				else if (torhs->index<tolhs->index)
				{
					if (tolhs->coefficient == 0 && tolhs->index != 0)
					{
						tolhs = tolhs->next;
						continue;
					}
					cur->index = tolhs->index;
					cur->coefficient = tolhs->coefficient;
					link<comparable> *tmp;
					tmp = new link<comparable>();
					cur->next = tmp;
					cur = tmp;
					tolhs = tolhs->next;
				}
				else
				{
					if (tolhs->coefficient+torhs->coefficient == 0 && tolhs->index != 0)
					{
						tolhs = tolhs->next;
						torhs = torhs->next;
						continue;
					}
					cur->index = tolhs->index;
					cur->coefficient = tolhs->coefficient + torhs->coefficient;
					if (!(cur->coefficient == (comparable)0 && cur->index == (comparable)0))
					{
						link<comparable> *tmp;
						tmp = new link<comparable>();
						cur->next = tmp;
						cur = tmp;
					}
					tolhs = tolhs->next;
					torhs = torhs->next;
				}
			}
		}
		cur->next = nullptr;
		return calculator(result);
	}
	calculator operator-(const calculator &rhs)//重载减号
	{
		return *this + (-rhs);
	}
	calculator operator*(const calculator &rhs)//重载乘号
	{
		link<comparable> *tolhs = root, *torhs = rhs.root, *temp, *tocreate;
		calculator result;
		while (tolhs->next != nullptr)
		{
			temp = new link<comparable>();
			link<comparable> *calrhs = torhs, *tmpsave = temp;
			while (calrhs->next != nullptr)//对每一项依次相乘后相加
			{
				temp->coefficient = tolhs->coefficient*calrhs->coefficient;
				temp->index = tolhs->index + calrhs->index;
				tocreate = new link<comparable>();
				temp->next = tocreate;
				temp = tocreate;
				calrhs = calrhs->next;
			}
			temp->coefficient = (comparable)0;
			temp->index = (comparable)0;
			temp->next = nullptr;
			calculator toadd(tmpsave);
			result = result + toadd;
			tolhs = tolhs->next;
		}
		return result;
	}
	calculator MUL()//微分运算
	{
		link<comparable> *result, *tmp,*change=root;
		result = new link<comparable>();
		tmp = result;
		while (change->index != 0)
		{
			tmp->coefficient = change->coefficient*change->index;
			tmp->index = change->index - 1;
			link<comparable> *thenext = new link<comparable>();
			tmp->next = thenext;
			tmp = thenext;
			change = change->next;
		}
		tmp->coefficient = (comparable)0;
		tmp->index = (comparable)0;
		tmp->next = nullptr;
		calculator ans(result);
		return ans;
	}
	pair<calculator<comparable>,calculator<comparable>> operator/(const calculator rhs)//重载除法（返回第一个为除的结果，第二个为余数）
	{
		link<comparable>  *tolhs, *torhs = rhs.root, *mod, *result, *modlast, *resultlast,*modroot;
		result = new link<comparable>();
		int flagmod = 0, flagdev = 0;
		calculator<comparable> ans(result),copylhs(*this);
		tolhs = copylhs.root;
		modroot = nullptr;
		modlast = nullptr;
		mod = nullptr;
		while (copylhs.root->next != nullptr)
		{
			if (copylhs.root->index >= torhs->index&&copylhs.root->coefficient%torhs->coefficient==0)
			{
				comparable indtmp = copylhs.root->index - torhs->index,coetmp= copylhs.root->coefficient/torhs->coefficient;
				link<comparable> *todev;
				todev = new link<comparable>();
				todev->coefficient = coetmp;
				todev->index = indtmp;
				todev->next = new link<comparable>();
				calculator<comparable> dev(todev);
				ans = ans + dev;
				dev = dev*rhs;
				copylhs = copylhs - dev;
				tolhs = copylhs.root;
			}
			else
			{
				mod = new link<comparable>();
				mod->coefficient = copylhs.root->coefficient;
				mod->index = copylhs.root->index;
				mod->next = nullptr;
				if (flagmod == 0)
				{
					modroot = mod;
				}
				if (flagmod != 0)
				{
					modlast->next = mod;
				}
				modlast = mod;
				flagmod = 1;
				copylhs.root = copylhs.root->next;
				delete tolhs;
				tolhs = copylhs.root;
			}
		}
		if (flagmod == 0)
		{
			modroot = new link<comparable>();
		}
		else
		{
			mod->next = new link<comparable>();
		}
		calculator themod(modroot);
		pair<calculator<comparable>, calculator<comparable>> res;
		res.first = ans;
		res.second = themod;
		return res;
	}
	link<comparable> *getroot()
	{
		return root;
	}
private:
	link<comparable> *root;//实际存储节点（相当于头结点）
};
int main()
{
	link<int>  in1, in2;
	vector<link<int>> root1,root2;
	int a, b;
	ifstream input("G:\\cs\\coding\\c++\\homework\\calculatorin.txt");
	ofstream output("G:\\cs\\coding\\c++\\homework\\calculatorout.txt");
	while (input >> a >> b, a)
	{
		in1.coefficient = a;
		in1.index = b;
		root1.push_back(in1);
	}
	in1.coefficient = 0;
	in1.index = 0;
	root1.push_back(in1);
	calculator<int> num1(root1);
	while (input >> a >> b, a)
	{
		in2.coefficient = a;
		in2.index = b;
		root2.push_back(in2);
	}
	in2.coefficient = 0;
	in2.index = 0;
	root2.push_back(in2);
	calculator<int> num2(root2);
	int thetype;
	input>>thetype;
	calculator<int> result;
	pair<calculator<int>,calculator<int>> theresult;
	switch(thetype)
	{
		case 0:
		result=num1+num2;
		num1.print(output);
		output<<"+"<<endl;
		num2.print(output);
		output<<"="<<endl;
		result.print(output);
		break;
		case 1:
		result=num1-num2;
		num1.print(output);
		output<<"-"<<endl;
		num2.print(output);
		output<<"="<<endl;
		result.print(output);
		break;
		case 2:
		result=num1*num2;
		num1.print(output);
		output<<"*"<<endl;
		num2.print(output);
		output<<"="<<endl;
		result.print(output);
		break;
		case 3:
		num1.print(output);
		output<<"dx="<<endl;
		num1.MUL().print(output);
		num2.print(output);
		output<<"dx="<<endl;
		num2.MUL().print(output);
		break;
		case 4:
		theresult=num1/num2;
		num1.print(output);
		output<<"/"<<endl;
		num2.print(output);
		output<<"="<<endl;
		theresult.first.print(output);
		output<<"%"<<endl;
		theresult.second.print(output);
		break;
		default:
		break;
	}
	return 0;
}
#endif