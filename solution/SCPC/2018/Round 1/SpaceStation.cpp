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


const int MAX_N = 2e5+55;
const int MAX_M = 4e5+55;


int N, M;
int d[MAX_N];
queue<int> q;
unordered_set<int> adjNodes[MAX_N];


bool has_edge(int u, int v) {
	return adjNodes[u].find(v) != adjNodes[u].end();
}


void add_edge(int u, int v) {
	adjNodes[u].insert(v);
	adjNodes[v].insert(u);
	++d[u], ++d[v];
}


void remove_edge(int u, int v) {
	adjNodes[u].erase(v);
	adjNodes[v].erase(u);
	--d[u], --d[v];
}


int solve() {
	int ans = N;
	while (!q.empty()) q.pop();
	for (int i = 1; i <= N; ++i)
		if (d[i] == 2) q.push(i);
	while (!q.empty()) {
		int target = q.front();
		q.pop();
		vector<int> a;
		foreach(it, adjNodes[target]) a.push_back(*it);
		if (int(a.size()) != 2) {
			// cout << "			??? " << target << " " << int(a.size()) << endl;
			continue;
		}
		int u = a[0], v = a[1];
		if (has_edge(u, v)) {
			--ans;
			remove_edge(target, u);
			remove_edge(target, v);
			if (d[u] == 2) q.push(u);
			if (d[v] == 2) q.push(v);
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("SpaceStation.in", "r", stdin);
	freopen("SpaceStation.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) {
			adjNodes[i].clear();
			d[i] = 0;
		}
		for (int i = 0; i < M; ++i) {
			int x, y;
			cin >> x >> y;
			add_edge(x, y);
		}
		cout << "Case #" << test_id << endl;
		cout << solve() << endl;
	}

	return 0;
}