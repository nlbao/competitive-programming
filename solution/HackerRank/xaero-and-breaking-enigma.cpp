#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


typedef struct Treap* pTreap;
struct Treap {	// Implicit Treap, 0-base indexed
	int prior, value, cnt;
	bool rev;	// 1 = reverse, 0 = not
	pTreap l, r;
	Treap(int x = 0) {
		value = x;
		prior = (rand()<<16)^rand();
		cnt = 1;
		l = r = 0;
	}
};

inline int getCnt(pTreap p) { return p ? p->cnt : 0;	}
inline void upNode(pTreap p) {
	if (!p) return;
	p->cnt = getCnt(p->l) + getCnt(p->r) + 1;
}

void push(pTreap p) {
	if (p && p->rev) {
		p->rev = 0;
		swap(p->l, p->r);
		if (p->l) p->l->rev ^= 1;
		if (p->r) p->r->rev ^= 1;
	}
}

void merge(pTreap & p, pTreap u, pTreap v) {
	push(u), push(v);
	if (!u || !v)
		p = u ? u : v;
	else if (u->prior > v->prior)
		merge(u->r, u->r, v), p = u;
	else
		merge(v->l, u, v->l), p = v;
	upNode(p);
}

void split(pTreap p, pTreap &u, pTreap &v, int key, int add = 0) {
	if (!p) return void(u = v = 0);
	push(p);
	int crrKey = add + getCnt(p->l);
	if (key <= crrKey)
		split(p->l, u, p->l, key, add), v = p;
	else
		split(p->r, p->r, v, key, crrKey + 1), u = p;
	upNode(p);
}

void reverse(pTreap p, int l, int r) {
	pTreap t1, t2, t3;
	split(p, t1, t2, l);	// t1 = [0, l-1]
	split(t2, t2, t3, r-l+1);	// t2 = [l, r]
	t2->rev ^= 1;
	merge(p, t1, t2);
	merge(p, p, t3);
}

void insert(pTreap &p, int key, int value) {
	pTreap u, v, q = new Treap(value);
	split(p, u, v, key);
	merge(p, u, q);
	merge(p, p, v);
}

void remove(pTreap &p) {
	if (!p) return;
	remove(p->l);
	remove(p->r);
	delete p;
}


const int MAX_N = 1e5+55;
const ll oo = 1e16;


int n, m;
int id[MAX_N], p[MAX_N], ans[MAX_N], a[MAX_N];
string s;
ll K, f[MAX_N];


void printID(pTreap p) {
	if (!p) return;
	push(p);
	printID(p->l);
	id[++m]=p->value;
	printID(p->r);
}


int getRoot(int u) {
	return p[u]==u ? u : p[u]=getRoot(p[u]);
}


bool solve() {
	filla(id, 1);
	fori(i,1,n) a[i]=(s[i-1]=='?') ? -1 : s[i-1]-'a';
	fori(i,1,n) if (a[i]>=0) {
		int u=getRoot(i);
		if (!id[u] && ans[u]!=a[i]) return 0;
		ans[u]=a[i];
		id[u]=0;
	}
	m=0;
	fori(i,1,n) if (a[i]<0) {
		int u=getRoot(i);
		if (id[u]) {
			id[u]=0;
			a[++m]=u;
		}
	}
	if (m<1) return K==1;

	f[m+1]=1;
	ford(i,m,1) f[i]=min(f[i+1]*26LL, oo);
	fori(i,1,m) {
		int u=a[i];
		fori(x,0,25) {
			if (f[i+1]<K) K-=f[i+1];
			else {
				ans[u]=x;
				break;
			}
		}
	}
	return K<=1;
}


int main() {
#ifdef DEBUG
	freopen("xaero-and-breaking-enigma.in", "r", stdin);
	freopen("xaero-and-breaking-enigma.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	pTreap root=0;
	int nQ;
	cin >> n >> nQ >> K;
	cin >> s;
	fori(i,1,n) insert(root, i-1, i);
	fori(i,1,nQ) {
		int x, y;
		cin >> x >> y;
		if (x>=y) continue;
		reverse(root, x-1, y-1);
	}
	m=0;
	printID(root);
	remove(root);

	fori(i,1,n) p[i]=i;
	fori(i,1,n) {
		int u=getRoot(i);
		int v=getRoot(id[i]);
		if (u!=v) p[u]=v;
	}

	if (!solve()) cout << "Bad Luck Allen" << endl;
	else {
		fori(i,1,n) cout << char(ans[getRoot(i)]+'a');
		cout << endl;
	}
	return 0;
}