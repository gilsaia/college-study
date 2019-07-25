### A
```C++
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
struct guest
{
	int val;
	string name;
};
guest fri[150020];
struct node
{
	int num, val;
	bool operator<(const node& rhs) const
	{
		if (val == rhs.val)
		{
			return num > rhs.num;
		}
		return val < rhs.val;
	}
};
struct indoor
{
    int t,p;
};
bool cmp(indoor a,indoor b)
{
    return a.t<b.t;
}
indoor invite[150020];
int res[150020];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int k, m, q;
		cin >> k >> m >> q;
		for (int i = 0; i < k; ++i)
		{
			cin >> fri[i].name >> fri[i].val;
		}
		int nowfri = 0, nowin = 0;
		priority_queue<node> que;
        for(int i=0;i<m;++i)
        {
            cin>>invite[i].t>>invite[i].p;
        }
        sort(invite,invite+m,cmp);
		for (int i = 0; i < m; ++i)
		{
            int t=invite[i].t,p=invite[i].p;
			while (nowfri < t)
			{
				++nowfri;
				node tmp;
				tmp.num = nowfri - 1;
				tmp.val = fri[nowfri - 1].val;
				que.push(tmp);
			}
			for (int i = 0; i < p; ++i)
			{
                if(que.empty())
                {
                    break;
                }
				++nowin;
				node tmp = que.top();
				que.pop();
				res[nowin] = tmp.num;
			}
		}
		while (nowfri < k)
		{
			++nowfri;
			node tmp;
			tmp.num = nowfri - 1;
			tmp.val = fri[nowfri - 1].val;
			que.push(tmp);
		}
		while (!que.empty())
		{
			++nowin;
			node tmp = que.top();
			que.pop();
			res[nowin] = tmp.num;
		}
		for (int i = 0; i < q; ++i)
		{
			int tmp;
			cin >> tmp;
			cout << fri[res[tmp]].name;
			if (i != q - 1)
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}
```
### B
```C++
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int isrem[10020];
ll val[10020];
int dag[10020];
int par[10020], siz[10020];
vector<int> G[10020];
void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		par[i] = i;
		siz[i] = 1;
	}
}
int find(int x)
{
	if (x == par[x])
	{
		return x;
	}
	return par[x] = find(par[x]);
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	par[x] = y;
	siz[y] += siz[x];
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int p, m;
		scanf("%d%d", &p, &m);
		for (int i = 1; i <= p; ++i)
		{
			scanf("%lld", &val[i]);
			isrem[i] = 0;
			dag[i] = 0;
            G[i].clear();
		}
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			++dag[u], ++dag[v];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		queue<int> que;
		for (int i = 1; i <= p; ++i)
		{
			if (dag[i] == 0 || dag[i] == 1)
			{
				que.push(i);
				isrem[i] = 1;
			}
		}
		while (!que.empty())
		{
			int tmp = que.front();
			que.pop();
			for (int i = 0; i < G[tmp].size(); ++i)
			{
				if (isrem[G[tmp][i]] == 0)
				{
					--dag[G[tmp][i]];
					if (dag[G[tmp][i]] < 2)
					{
						que.push(G[tmp][i]);
						isrem[G[tmp][i]] = 1;
					}
				}
			}
		}
		init(p);
		for (int i = 1; i <= p; ++i)
		{
			if (isrem[i])
			{
				continue;
			}
			for (int j = 0; j < G[i].size(); ++j)
			{
				if (isrem[G[i][j]])
				{
					continue;
				}
				if (!same(i, G[i][j]))
				{
					unite(i, G[i][j]);
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= p; ++i)
		{
			if (isrem[i])
			{
				continue;
			}
			if (siz[find(i)] & 1)
			{
				ans += val[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
```
### E
```C++
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int par[20060],nodesize[20060];
void init(int n)
{
    for(int i=0;i<=n;++i)
    {
        par[i]=i;
        nodesize[i]=1;
    }
}
int find(int x)
{
    if(x==par[x])
    {
        return x;
    }
    return par[x]=find(par[x]);
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    par[x]=y;
    nodesize[y]+=nodesize[x];
}
int res[100020];
struct edge
{
    int x,y;
    int time;
    bool operator<(const edge &rhs) const
    {
        return time<rhs.time;
    }
};
bool cmp(edge a,edge b)
{
    return a.time<b.time;
}
edge road[100020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        init(n);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&road[i].x,&road[i].y,&road[i].time);
        }
        sort(road,road+m,cmp);
        res[0]=0;
        for(int i=0;i<m;++i)
        {
            int x=road[i].x,y=road[i].y;
            if(same(x,y))
            {
                continue;
            }
            int sizx=nodesize[find(x)],sizy=nodesize[find(y)];
            res[i]+=(sizx*sizy*2);
            unite(x,y);
            res[i+1]=res[i];
        }
        for(int i=0;i<q;++i)
        {
            int tmptime;
            scanf("%d",&tmptime);
            edge tmp;
            tmp.time=tmptime;
            int tofind=upper_bound(road,road+m,tmp)-road-1;
            printf("%d\n",res[tofind]);
        }
    }
    return 0;
}
```
### G
```C++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXNUM = 4020;
struct SegTreeNode
{
    int val;
}segTree[MAXNUM];//定义线段树

/*
功能：构建线段树
root：当前线段树的根节点下标
arr: 用来构造线段树的数组
istart：数组的起始位置
iend：数组的结束位置
*/
void build(int root, int arr[], int istart, int iend)
{
    if(istart == iend)//叶子节点
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//递归构造左子树
        build(root*2+2, arr, mid+1, iend);//递归构造右子树
        //根据左右子树根节点的值，更新当前根节点的值
        segTree[root].val = max(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}
 /*
功能：线段树的区间查询
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[qstart, qend]: 此次查询的区间
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //查询区间和当前节点区间没有交集
    if(qstart > nend || qend < nstart)
        return 0;
    //当前节点区间包含在查询区间内
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //分别从左右子树查询，返回两者查询结果的较小值
    int mid = (nstart + nend) / 2;
    return max(query(root*2+1, nstart, mid, qstart, qend),
               query(root*2+2, mid + 1, nend, qstart, qend));

}
int val[1020];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>val[i];
        }
        build(1,val,1,n);
        int q;
        cin>>q;
        for(int i=0;i<q;++i)
        {
            int l,r;
            cin>>l>>r;
            int res=query(1,1,n,l,r);
            cout<<res<<endl;
        }
    }
    return 0;
}
```
### H

```C++
#include<iostream>
#include<algorithm>
using namespace std;
int seq[1020];
struct node
{
    int val;
    node *right,*left;
    node()
    {
        val=0;
        right=left=NULL;
    }
};
node * insert(node *root,int val)
{
    if(root==NULL)
    {
        root=new node;
        root->val=val;
        return root;
    }
    if(val>root->val)
    {
        root->right=insert(root->right,val);
    }
    else
    {
        root->left=insert(root->left,val);
    }
    return root;
}
void find(int val,node *root)
{

    if(val==root->val)
    {
        return;
    }
    if(val>root->val)
    {
        cout<<'W';
        find(val,root->right);
    }
    else
    {
        cout<<'E';
        find(val,root->left);
    }
    return;
}
void remove(node *root)
{
    if(root==NULL)
    {
        return;
    }
    remove(root->left);
    remove(root->right);
    delete root;
    return;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        node *root=NULL;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            root=insert(root,tmp);
        }
        int q;
        cin>>q;
        for(int i=0;i<q;++i)
        {
            int val;
            cin>>val;
            find(val,root);
            cout<<endl;
        }
        remove(root);
    }
    return 0;
}
```

### J
```C++
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fac[100020],inv[100020];
ll pow_mod(ll a, int b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}
ll mul(ll a,ll b,ll mod){///二进制，按位相乘
    a=(a%mod+mod)%mod;
    b=(b%mod+mod)%mod;
    ll ans=0;
    while(b){
        if(b&1) ans+=a,ans=(ans>=mod?ans-mod:ans);
        b>>=1; a<<=1;
        a=(a>=mod?a-mod:a);
    }
    return ans;
}
void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (b == 0) {
        d = a, x = 1, y = 0;
    } else {
        ext_gcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}
ll lucas(ll n,ll m,ll mod){
    ll ans=1;
    while(n&&m){
        ll a=n%mod,b=m%mod;
        if(a<b) return 0;
        ans=ans*fac[a]%mod*inv[b]%mod*inv[a-b]%mod;
        n/=mod,m/=mod;
    }
    return ans;
}

ll china(ll n,ll* a,ll* m){
    ll M=1,w,gcd,x,y,ans=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        w=M/m[i];
        ext_gcd(m[i],w,gcd,x,y);
        ans=(ans+mul(mul(y,w,M),a[i],M)+M)%M;
    }
    return ans;
}
void init(ll n)
{
    fac[0]=1;
    for(int i=1;i<=n;++i)
    {
        fac[i]=fac[i-1]*i%n;
    }
    inv[n-1]=pow_mod(fac[n-1],n-2,n);
    for(int i=n-2;i>=0;--i)
    {
        inv[i]=inv[i+1]*(i+1)%n;
    }
}
ll a[20],p[20];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=0;i<k;++i)
        {
            scanf("%lld",&p[i]);
            init(p[i]);
            a[i]=lucas(n,m,p[i]);
        }
        printf("%lld\n",china(k,a,p));
    }
    return 0;
}
```