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


const int MAX_N = (1<<15)+44;


int n, K, m;
int p[MAX_N], a[2][MAX_N], id[2][MAX_N];
vector<int> e[MAX_N];


int main() {
#ifdef DEBUG
	freopen("5060.in", "r", stdin);
	freopen("5060.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n >> K;
		m = 1<<n;
		fori(i,1,m) {
			cin >> p[i];
			a[0][i]=p[i];
			id[0][i]=i;
			e[i].clear();
		}
		int t=0;
		fori(turn,1,n) {
			int tt=t;
			t^=1;
			for (int i=1, c=1; i<m; i+=2, ++c) {
				int x=a[tt][i], y=a[tt][i+1];
				int u=id[tt][i], v=id[tt][i+1];
				if (x>y || (x==y && id[tt][i]<id[tt][i+1])) {
					id[t][c]=u;
					a[t][c]=min(p[u], x-y+K);
					e[u].pb(v);
				}
				else {
					id[t][c]=v;
					a[t][c]=min(p[v], y-x+K);
					e[v].pb(u);
				}
			}
			m >>= 1;
		}

		int u=id[t][1];
		cout << u << endl;
		m=sz(e[u]);
		fori(i,0,m-1) {
			cout << e[u][i];
			if (i<m-1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}