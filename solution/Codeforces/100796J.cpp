// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


typedef struct Node* pNode;
struct Node {
	int val, prior, cnt;
	pNode l, r, par;
	Node(int x=0) {
		val = x;	cnt = 1;
		prior = (rand()<<16) | rand();
		l = r = par = 0;
	}
};

inline int getCnt(pNode p) {	return p ? p->cnt : 0;	}
inline void upNode(pNode &p) {
	if (!p) return;
	p->cnt = getCnt(p->l) + getCnt(p->r) + 1;
	if (p->l) p->l->par = p;
	if (p->r) p->r->par = p;
}


void merge(pNode &p, pNode u, pNode v) {
	if (!u || !v) return void(p = u ? u : v);
	if (u->prior > v->prior) merge(u->r, u->r, v), p = u;
	else                     merge(v->l, u, v->l), p = v;
	upNode(p);
}

void split(pNode p, pNode &u, pNode &v, int key, int add = 0) {
	if (!p) return void(u = v = 0);
	int crrKey = add + getCnt(p->l);
	if (key <= crrKey) split(p->l, u, p->l, key, add), v = p;
	else               split(p->r, p->r, v, key, crrKey + 1), u = p;
	upNode(p);
}

pNode insert(pNode &p, int i, int val) {	// 0-based
	pNode t1, t2, newNode = new Node(val);
	split(p, t1, t2, i);
	merge(p, t1, newNode);
	merge(p, p, t2);
	return newNode;
}

int findPos(pNode p) {	// 0-based
	int c = getCnt(p->l);
	for (; p->par; p = p->par)
		if (p == p->par->r)
			c += getCnt(p->par->l) + 1;
	return c;
}


void remove(pNode &p) {
	if (!p) return;
	remove(p->l);
	remove(p->r);
	delete p;
}


const int MAX_N = 1e5+5;

pNode root, id[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100796J.in", "r", stdin);
	freopen("100796J.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	srand(time(0));
	root=0;
	int nQ=read(), n=0, nID=0;
	while (nQ--) {
		char ch;
		cin >> ch;
		int x = (ch=='O') ? read()-1 : nID++;	// 0-based
		if (ch=='F') {
			id[x]=insert(root, 0, x);
			++n;
		}
		else if (ch=='B') {
			id[x]=insert(root, n, x);
			++n;
		}
		else {
			int pos = findPos(id[x]);
			cout << min(pos, n-1-pos) << endl;
			--n;
			pNode t1, t2, t3;
			split(root, t1, t2, pos);
			split(t2, t2, t3, 1);
			merge(root, t3, t1);
		}
	}
	remove(root);

	return 0;
}