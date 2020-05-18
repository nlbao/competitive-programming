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


const int MAX_N = 1e5+15;
const int MOD = 1e9+7;
const int MAX_F = 4*MAX_N;

struct Node {
	int l, c;
	Node(int l=0, int c=0) : l(l), c(c) {}
	Node compose(const Node &o) {
		Node ans(l,c);
		if (o.l>ans.l) ans=o;
		else if (o.l==ans.l) ans.c=(ans.c+o.c)%MOD;
		return ans;
	}
};


int n, maxA, pos;
int a[MAX_N];
Node f[MAX_F], newNode;
map<int, int> id;


void build(int k, int l, int r) {
	f[k]=Node(0,0);
	if (l>=r) return;
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	build(kl, l, mid);
	build(kr, mid+1, r);
}


void update(int k, int l, int r) {
	if (l>pos || r<pos) return;
	if (l==r) {
		f[k]=f[k].compose(newNode);
		return;
	}
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	f[k]=f[kl].compose(f[kr]);
}


Node get(int k, int l, int r) {
	if (l>r || l>pos) return Node(0, 0);
	if (r<=pos) return f[k];
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	return get(kl, l, mid).compose(get(kr, mid+1, r));
}


int main() {
#ifdef DEBUG
	freopen("NTSEQ.in", "r", stdin);
	freopen("NTSEQ.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		cin >> a[i];
		id[a[i]];
	}
	maxA=0;
	foreach(it, id) it->sc = ++maxA;

	build(1,1,maxA);

	fori(i,1,n) {
		pos = id[a[i]]-1;
		Node t = get(1,1,maxA);
		int l = t.l+1, c = t.c;
		if (c==0) c=1;
		++pos;
		newNode=Node(l, c);
		update(1,1,maxA);
	}
	pos = maxA;
	cout << get(1,1,maxA).c << endl;

	return 0;
}