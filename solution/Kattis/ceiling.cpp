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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


struct Node {
	int val;
	Node *l, *r;
	Node(int x) {
		val = x;
		l=r=0;
	}
};


void remove(Node* &p) {
	if (!p) return;
	remove(p->l);
	remove(p->r);
	p = 0;
}


string getStr(Node *p) {
	if (!p) return "";
	return "1(" + getStr(p->l) + ")(" + getStr(p->r) + ")";
}


void add(Node* &p, int x) {
	if (!p) {
		p = new Node(x);
		return;
	}
	if (x < p->val) add(p->l, x);
	else add(p->r, x);
}


int main() {
#ifdef DEBUG
	freopen("ceiling.in", "r", stdin);
	freopen("ceiling.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	Node *root = NULL;
	int n, len;
	cin >> n >> len;
	set<string> q;
	for (int i = 0; i < n; ++i) {
		remove(root);
		for (int k = 0; k < len; ++k) {
			int x = read();
			add(root, x);
		}
		q.insert(getStr(root));
	}
	cout << q.size() << endl;


	return 0;
}