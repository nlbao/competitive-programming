#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


// Eertree
namespace Eertree {
#define check(i, x) (i >= 0 && a[i] == x)

const int MAX_N = 1e5 + 5;

struct Node {
	int len, link;
	map<int, int> nexts;

	Node(int l = 0, int pre = 0) {
		len = l;
		link = pre;
		nexts.clear();
	}

	void operator = (const Node &other) {
		len = other.len;
		link = other.link;
		nexts = other.nexts;
	}

	bool hasNext(int x) {
		return nexts.find(x) != nexts.end();
	}
};

int nNode, last;
int a[MAX_N];
Node tree[MAX_N];

void init() {
	nNode = 2;
	last = 1;
	tree[0] = Node(-1, 0);
	tree[1] = Node(0, 0);
}

void add(int x, int i) {
	a[i] = x;
	int p = last, k;
	while (!check(i-1-tree[p].len, x))
		p = tree[p].link;
	if (tree[p].hasNext(x)) {
		last = tree[p].nexts[x];
		return;
	}
	last = nNode++;
	tree[last] = Node(tree[p].len+2, 1);
	tree[p].nexts[x] = last;
	if (tree[last].len == 1) return;
	do {
		p = tree[p].link;
	} while (!check(i-1-tree[p].len, x));
	tree[last].link = tree[p].nexts[x];
}
};


string s;


int main() {
#ifdef DEBUG
	freopen("1960.in", "r", stdin);
	freopen("1960.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	Eertree::init();

	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		int x = s[i] - 'a';
		Eertree::add(x, i);
		cout << Eertree::nNode - 2 << ' ';
	}

	return 0;
}