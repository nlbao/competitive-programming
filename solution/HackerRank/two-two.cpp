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


const int MAX_A = 12;

// Aho-Corasick
typedef struct Node* pNode;
struct Node {
	pNode nexts[MAX_A], link;
	int cnt, len;

	Node(int l, int c) {
		fori(i,0,MAX_A-1) nexts[i]=0;
		link = 0;	len = l;	cnt=c;
	}

	pNode add(int x, int val) {
		if (!nexts[x]) nexts[x] = new Node(len+1, val);
		else if (val) nexts[x]->cnt = 1;
		return nexts[x];
	}
};


void init(pNode root) {
	if (!root) return;
	queue<pNode> q;
	q.push(root);
	while (!q.empty()) {
		pNode p = q.front();	q.pop();
		if (p->link) p->cnt += p->link->cnt;
		fori(x,0,MAX_A-1) {
			pNode u = p, v = p->nexts[x];
			if (!v) continue;
			q.push(v);
			if (u != root) {
				u = p->link;
				while (u != root && !u->nexts[x]) u = u->link;
				if (u->nexts[x]) u = u->nexts[x];
			}
			v->link = u;
		}
	}
}


void remove(pNode &p) {
	if (!p) return;
	fori(i,0,MAX_A-1) remove(p->nexts[i]);
	delete p;
}


int main() {
#ifdef DEBUG
	freopen("two-two.in", "r", stdin);
	freopen("two-two.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	pNode root = new Node(0, 0);
	int a[1111], len=1;
	filla(a, 0);
	a[1]=1;
	fori(turn,0,800) {
		pNode p=root;
		ford(i,len,1) {
			p = p->add(a[i], i==1 ? 1 : 0);
		}
		int c=0;
		fori(i,1,len) {
			a[i] = a[i]*2 + c;
			c = a[i] / 10;
			a[i] %= 10;
		}
		if (c) a[++len]=c;
	}

	init(root);

	int nTest = read();
	string s;
	while (nTest--) {
		cin >> s;
		pNode p=root;
		int n=sz(s);
		ll ans=0;
		fori(i,0,n-1) {
			int x=s[i]-'0';
			while (p != root && !p->nexts[x]) p = p->link;
			if (p->nexts[x]) p = p->nexts[x];
			ans += p->cnt;
		}
		cout << ans << endl;
	}

	return 0;
}