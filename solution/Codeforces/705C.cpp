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


const int MAX_N = 3e5+33;


int n, nQ, ans, id;
int pos[MAX_N];
bool ok[MAX_N];
vector<int> a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("705C.in", "r", stdin);
	freopen("705C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	ans = 0;
	id = 0;
	filla(pos, 0);
	filla(ok, true);
	while (nQ--) {
		int qtype = read();
		if (qtype == 1) {
			int x = read();
			++id;	++ans;
			a[x].pb(id);
			a[0].pb(id);
		}
		else if (qtype == 2) {
			int x = read();
			while (pos[x] < (int)a[x].size()) {
				int u = a[x][pos[x]++];
				if (ok[u]) {
					ok[u] = false;
					--ans;
				}
			}
		}
		else {
			int t = read();
			while (pos[0] < t && pos[0] < (int)a[0].size()) {
				int u = a[0][pos[0]++];
				if (ok[u]) {
					ok[u] = false;
					--ans;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}