#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<utility>
#include<vector>
#include<map>
#include<iomanip>
const int INTERVAL=40;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;
using std::string;
using std::memset;
using std::getline;
using std::istream;
using std::ostream;
using std::right;
using std::left;
using std::setw;
using std::endl;
using std::cin;
using std::cout;
using std::priority_queue;
using std::fstream;
using std::ifstream;
using std::ofstream;
template <typename Save>
struct HuffmantreeNode
{
	int weight;
	Save element;
	HuffmantreeNode *left, *right;
	bool isleaf;
	HuffmantreeNode(int wei = 0, Save ele = 0, HuffmantreeNode *l = nullptr, HuffmantreeNode *r = nullptr, bool leaf = 0) :
		weight{ wei }, element{ ele }, left{ l }, right{ r }, isleaf{ leaf } {}
	bool operator<(const HuffmantreeNode &rhs)
	{
		if (weight == rhs.weight)
		{
			return element>rhs.element;
		}
		return weight>rhs.weight;
	}
};
template <typename Save>
struct HuffmantreeComparable
{
	bool operator()(HuffmantreeNode<Save> *a, HuffmantreeNode<Save> *b)
	{
		return (*a)<(*b);
	}
};
template <typename Save>
class Huffmantree
{
public:
	~Huffmantree()
	{
		deleteNode(root);
	}
	void buildTree(istream &in, ostream &out)
	{
		auto inpos=in.tellg();
        map<Save, int> tocount;
		string theline;
		while (getline(in, theline))
		{
			for (auto i : theline)
			{
				tocount[i]++;
			}
		}
		priority_queue<HuffmantreeNode<Save>*, vector<HuffmantreeNode<Save>*>, HuffmantreeComparable<Save>> que;
		out << left << setw(12) << "Element" << setw(12) << "nums" << endl << right;
		for (auto i = tocount.begin(); i != tocount.end(); i++)
		{
			HuffmantreeNode<Save> *tmp = new HuffmantreeNode<Save>(i->second, i->first, nullptr, nullptr, true);
			out << left << setw(12) << i->first << setw(12) << i->second << endl << right;
			que.push(tmp);
		}
        in.clear();
		in.seekg(inpos);
		HuffmantreeNode<Save> *thelast = nullptr;
		while (que.size()>1)
		{
			HuffmantreeNode<Save> *first = que.top();
			que.pop();
			HuffmantreeNode<Save> *second = que.top();
			que.pop();
			thelast = new HuffmantreeNode<Save>(first->weight + second->weight, (Save)0, first, second);
			que.push(thelast);
		}
		root = que.top();
		buildtranslate(root,out);
        out<<"result"<<endl;
		while (getline(in, theline))
		{
			for (auto i : theline)
			{
				out << translate[i];
			}
		}
	}
    void totranslate(istream &in,ostream &out)
    {
        out << left << setw(12) << "Element"  <<setw(12)<<"code"<< endl << right;
        for(auto i=translate.begin();i!=translate.end();i++)
        {
            out << left << setw(12) << i->first << setw(12) << i->second << endl << right;
        }
        out<<"result"<<endl;
        char tmp;
        HuffmantreeNode<Save> *cur=root;
        int num=0;
        while(in>>tmp)
        {
            if(tmp=='0')
            {
                cur=cur->left;
            }
            else if(tmp=='1')
            {
                cur=cur->right;
            }
            if(cur->isleaf)
            {
                out<<cur->element;
                if(++num==INTERVAL)
                {
                    out<<endl;
                    num=0;
                }
                cur=root;
            }
        }
    }
	void buildtranslate(HuffmantreeNode<Save> *root,ostream& out=cout)
	{
		string tmp;
        out << left << setw(12) << "Element"  <<setw(12)<<"code"<< endl << right;
		buildtranslate(root, tmp,out);
	}
private:
	void buildtranslate(HuffmantreeNode<Save> *root, string code,ostream& out=cout)
	{
		if (root->isleaf)
		{
            out << left << setw(12) << root->element << setw(12) << code << endl << right;
            translate[root->element] = code;
		}
		else
		{
			buildtranslate(root->left, code + '0',out);
			buildtranslate(root->right, code + '1',out);
		}
	}
	void deleteNode(HuffmantreeNode<Save> *root)
	{
		if(root!=nullptr)
		{
			deleteNode(root->left);
			deleteNode(root->right);
			delete root;
		}
	}
	HuffmantreeNode<Save> *root;
	map<Save, string> translate;
};
int main()
{
	ifstream in1("G:\\cs\\coding\\c++\\homework\\huffmantreeinput1.txt");
	ofstream out1("G:\\cs\\coding\\c++\\homework\\huffmantreeoutput1.txt");
    ifstream in2("G:\\cs\\coding\\c++\\homework\\huffmantreeinput2.txt");
    ofstream out2("G:\\cs\\coding\\c++\\homework\\huffmantreeoutput2.txt");
	Huffmantree<char> ans;
	ans.buildTree(in1, out1);
    ans.totranslate(in2,out2);
	return 0;
}
#endif