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


struct Node;
typedef Node* pNode;
struct Node {
	int cnt;
	pNode pLeft, pRight;
	Node(int cnt, pNode pLeft, pNode pRight) : cnt(cnt), pLeft(pLeft), pRight(pRight) {}
};


const int MAX_A = 1e4+44;
const int MAX_N = 1e4+44;

int n, maxA, nQ, value;
map<int, int> id;
int revID[MAX_A], a[MAX_N];
pNode root[MAX_N];


inline int getCnt(pNode p) {	return p ? p->cnt : 0;	}
inline pNode getLeft(pNode p) {	return p ? p->pLeft : 0;	}
inline pNode getRight(pNode p) {	return p ? p->pRight : 0;	}


pNode update(pNode p, int l, int r) {
	if (l>r) return 0;
	if (l>value || r<value) return p;
	if (l==r) return new Node(getCnt(p)+1, 0, 0);
	int mid=(l+r)>>1;
	return new Node(
		getCnt(p)+1,
		update(getLeft(p), l, mid),
		update(getRight(p), mid+1, r)
	);
}

int get(pNode a, pNode b, int l, int r, int k) {
	if (l>r) return -1;
	if (l==r) return l;
	int mid=(l+r)>>1;
	int cnt=getCnt(getLeft(b)) - getCnt(getLeft(a));
	if (k<=cnt) return get(getLeft(a), getLeft(b), l, mid, k);
	return get(getRight(a), getRight(b), mid+1, r, k-cnt);
}


int main() {
#ifdef DEBUG
	freopen("186.in", "r", stdin);
	freopen("186.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> nQ;
		id.clear();
		fori(i,1,n) {
			cin >> a[i];
			id[a[i]];
		}
		maxA=0;
		foreach(it, id) {
			it->sc=++maxA;
			revID[maxA]=it->fr;
		}

		root[0]=new Node(0, 0, 0);
		fori(i,1,n) {
			value=id[a[i]];
			root[i] = update(root[i-1], 1, maxA);
		}

		cout << "Case #" << testid << ":\n";
		while (nQ--) {
			int l, r, k;
			cin >> l >> r >> k;
			int t=get(root[l-1], root[r], 1, maxA, k);
			cout << revID[t] << endl;
		}
	}

	return 0;
}