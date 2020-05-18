#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=200010;
const int INF=1000000000;

inline pii operator + (pii a,int b)
{
	return pii(a.X+b,a.Y);
}

int n,m;
vector<int> v[MaxN];
int head,tail,Q[MaxN];
int pre[MaxN],flag[MaxN],size[MaxN],way[MaxN],pos[MaxN],from[MaxN],color[MaxN];
vector<int> list[MaxN];

struct node
{
	node *Lc,*Rc;
	int L,R;
	pii Lv,Rv;
	node () {}
	node (int _L,int _R)
	{
		L=_L;
		R=_R;
	}
};

set<pii> heap[MaxN];

struct segment
{
	int top,len;
	node *root;
	node *build(int L,int R)
	{
		node *it=new node(L,R);
		it->Lv=it->Rv=pii(-INF,0);
		int m=(L+R)>>1;
		if (L<R)
		{
			it->Lc=build(L,m);
			it->Rc=build(m+1,R);
		}
		return it;
	}
	void build(int n)
	{
		top=n;
		len=list[n].size()-1;
		root=build(0,len);
	}
	void update(node *it,node *Lc,node *Rc)
	{
		it->Lv=max(Lc->Lv,Rc->Lv+(Rc->L-it->L));
		it->Rv=max(Rc->Rv,Lc->Rv+(it->R-Lc->R));
	}
	void modify(node *it,int x,pii &p)
	{
		if (it->L==it->R)
		{
			it->Lv=it->Rv=p;
			return;
		}
		int m=(it->L+it->R)>>1;
		if (x<=m)
			modify(it->Lc,x,p);
		else
			modify(it->Rc,x,p);
		update(it,it->Lc,it->Rc);
	}
	node query(node *it,int x,int y)
	{
		if (it->L==x&&it->R==y)
			return *it;
		int m=(it->L+it->R)>>1;
		if (y<=m)
			return query(it->Lc,x,y);
		if (x>m)
			return query(it->Rc,x,y);
		node L=query(it->Lc,x,m);
		node R=query(it->Rc,m+1,y);
		node p(x,y);
		update(&p,&L,&R);
		return p;
	}
	void modify(int x)
	{
		heap[pre[top]].erase(root->Lv+1);
		pii p=*heap[x].rbegin();
		modify(root,pos[x],p);
		heap[pre[top]].insert(root->Lv+1);
	}
	node query(int x,int y)
	{
		return query(root,x,y);
	}
}T[MaxN];

inline void modify(int x)
{
	for (;x;x=pre[from[x]])
		T[from[x]].modify(x);
}

inline void add(int x)
{
	color[x]=0;
	heap[x].insert(pii(0,x));
	modify(x);
}

inline void del(int x)
{
	color[x]=1;
	heap[x].erase(pii(0,x));
	modify(x);
}

inline pii get_ans(int x)
{
	pii p(0,x);
	for (int dis=0,cur=x,precur=0;cur;dis+=pos[cur]+1,cur=pre[from[cur]])
	{
		int k=from[cur];
		if (precur)
		{
			heap[cur].erase(T[from[precur]].root->Lv+1);
			T[k].modify(cur);
		}
		p=max(p,T[k].query(0,pos[cur]).Rv+dis);
		p=max(p,T[k].query(pos[cur],T[k].len).Lv+dis);
		if (precur)
		{
			heap[cur].insert(T[from[precur]].root->Lv+1);
			T[k].modify(cur);
		}
		precur=cur;
	}
	return p;
}

void clear()
{
	for (int i=1;i<=n;++i)
	{
		v[i].clear();
		list[i].clear();
		heap[i].clear();
		heap[i].insert(pii(-INF,0));
	}
}

void init()
{
	scanf("%d%d",&n,&m);
	clear();
	for (int i=2;i<=n;++i)
	{
		scanf("%d",&pre[i]);
		v[pre[i]].push_back(i);
	}
	Q[head=tail=1]=1;
	while (head<=tail)
	{
		int x=Q[head++];
		for (auto y : v[x])
			Q[++tail]=y;
	}
	for (int i=1;i<=n;++i)
		flag[i]=1;
	for (int k=tail;k>=1;--k)
	{
		int i=Q[k];
		size[i]=1;
		for (auto j : v[i])
			size[i]+=size[j];
		if (!v[i].empty())
		{
			int get,most=0;
			for (auto j : v[i])
				if (most<size[j])
				{
					get=j;
					most=size[j];
				}
			way[i]=get;
			flag[get]=0;
		}
		else
			way[i]=0;
	}
	for (int i=1;i<=n;++i)
		if (flag[i])
		{
			for (int x=i;x;x=way[x])
			{
				pos[x]=list[i].size();
				list[i].push_back(x);
				from[x]=i;
			}
			T[i].build(i);
		}
	for (int i=1;i<=n;++i)
		add(i);
}

void work()
{
	while (m--)
	{
		int x;
		scanf("%d",&x);
		int flag=0;
		if (color[x])
		{
			flag=1;
			add(x);
		}
		pii p=get_ans(x);
		printf("%d\n",p.Y);
		if (!flag)
		{
			del(x);
		}
	}
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		init();
		work();
	}
	return 0;
}
