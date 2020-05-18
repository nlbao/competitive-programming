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


const int MAX_N = 1e5+5;
const ll oo = 1e18;


int n, u, v, pos, value;
int a[MAX_N];

struct Node;
typedef Node* pNode;
struct Node {
	int l, r;
	ll f, s[2][2], sleft[2][2], sright[2][2];
	Node *pl, *pr;

	Node(int l=1, int r=0, ll val=0) : l(l), r(r) {
		pl=pr=0;
		fori(i,0,1) fori(j,0,1) s[i][j]=sleft[i][j]=sright[i][j]=-oo;
		init(val);
	}

	Node(const pNode o) {
		l=o->l, r=o->r;
		f=o->f;
		fori(i,0,1) fori(j,0,1) {
			s[i][j]=o->s[i][j];
			sleft[i][j]=o->sleft[i][j];
			sright[i][j]=o->sright[i][j];
		}
		pl=pr=0;
	}

	inline void init(ll val) {
		f=val;
		s[0][0] = sleft[0][0] = sright[0][0] = val;
		s[1][1] = sleft[1][1] = sright[1][1] = -val;
	}

	inline void pushUp() {
		if (l>=r) return;
		int mid=(l+r)>>1;
		int odd = (r-l+1)&1, oddL=(mid-l+1)&1, oddR=(r-mid)&1;
		f=max(pl->f, pr->f);
		f=max(f, pl->sright[0][0] + max(pr->sleft[1][0], pr->sleft[1][1]));
		f=max(f, pl->sright[0][1] + max(pr->sleft[0][0], pr->sleft[0][1]));

		fori(i,0,1) fori(j,0,1) s[i][j]=sleft[i][j]=sright[i][j]=-oo;
		if (odd) s[0][0] = pl->s[0][1-oddL] + pr->s[oddL][0];
		if (odd) s[1][1] = pl->s[1][oddL] + pr->s[1-oddL][1];
		if (!odd) s[0][1] = pl->s[0][1-oddL] + pr->s[oddL][1];
		if (!odd) s[1][0] = pl->s[1][oddL] + pr->s[1-oddL][0];

		sleft[0][0] = max(pl->sleft[0][0], pl->s[0][1-oddL] + pr->sleft[oddL][0]);
		sleft[0][1] = max(pl->sleft[0][1], pl->s[0][1-oddL] + pr->sleft[oddL][0]);
		sleft[1][0] = max(pl->sleft[1][0], pl->s[1][oddL] + pr->sleft[1-oddL][0]);
		sleft[1][1] = max(pl->sleft[1][1], pl->s[1][oddL] + pr->sleft[1-oddL][1]);

		sright[0][0] = max(pr->sright[0][0], pl->s[0][oddR] + pr->s[1-oddR][0]);
		sright[0][1] = max(pr->sright[0][1], pl->s[0][oddR] + pr->s[1-oddR][1]);
		sright[1][0] = max(pr->sright[1][0], pl->s[1][1-oddR] + pr->s[oddR][0]);
		sright[1][1] = max(pr->sright[1][1], pl->s[1][1-oddR] + pr->s[oddR][1]);

		// cout << l << " " << r << ": " << s[0][1] << " " << s[1][0] << " " << pr->s[oddL][1] << endl;
	}
};


pNode build(int l, int r) {
	if (l==r) return new Node(l,r,a[l]);
	int mid=(l+r)>>1;
	pNode p = new Node(l,r);
	p->pl=build(l,mid);
	p->pr=build(mid+1,r);
	p->pushUp();
	return p;
}


void update(pNode p, int l, int r) {
	if (l>pos || r<pos) return;
	if (l==r) {
		p->init(value);
		return;
	}
	int mid=(l+r)>>1;
	update(p->pl, l, mid);
	update(p->pr, mid+1, r);
	p->pushUp();
}


pNode get(const pNode p, int l, int r) {
	if (l>v || r<u) return 0;
	if (u<=l && r<=v) return new Node(p);
	int mid=(l+r)>>1;
	pNode a=get(p->pl, l, mid);
	pNode b=get(p->pr, mid+1, r);
	if (!a || !b) return a ? a : b;
	pNode t = new Node(l,r);
	t->pl=a;	t->pr=b;
	t->pushUp();
	return t;
}


void remove(pNode &p) {
	if (!p) return;
	remove(p->pl);
	remove(p->pr);
	delete p;
}


int main() {
#ifdef DEBUG
	freopen("maximise-alternate-sum-subarray.in", "r", stdin);
	freopen("maximise-alternate-sum-subarray.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> a[i];
	pNode root = build(1,n);

	int nQ=read();
	while (nQ--) {
		char ch;
		cin >> ch;
		if (ch=='Q') {
			cin >> u >> v;
			pNode t=get(root,1,n);
			if (t) {
				cout << t->f << endl;
				remove(t);
			}
			else cout << endl;
		}
		else {
			cin >> pos >> value;
			update(root,1,n);
		}
	}
	remove(root);

	return 0;
}