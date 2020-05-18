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


const int MAX_N = 1011;
const ll MOD = 1e6+3;


int n, m;
int c[MAX_N][MAX_N], a[MAX_N];
int b[MAX_N][MAX_N];


ll solve(int h, int n) {
	if (n<2) return 1;
	int m=0, root=b[h][1];
	fori(i,1,n) if (b[h][i]<root) b[h+1][++m]=b[h][i];
	ll ans = solve(h+1, m);
	int x=m;
	m=0;
	fori(i,1,n) if (b[h][i]>root) b[h+1][++m]=b[h][i];
	ans = (ans * solve(h+1, m)) % MOD;
	int y=m;
	if (x>0 && y>0) ans = (ans * c[x+y][x]) % MOD;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("5058.in", "r", stdin);
	freopen("5058.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(c, 0);
	c[0][0]=1;
	fori(i,1,MAX_N-1) {
		c[i][0]=c[i][i]=1;
		fori(j,1,i-1) c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}

	int nTest=read();
	map<int, int> id;
	while (nTest--) {
		cin >> n >> m;
		id.clear();
		fori(i,1,n) {
			cin >> a[i];
			id[a[i]];
		}
		int t=0;
		foreach(it, id) it->sc=++t;
		fori(i,1,n) b[1][i]=id[a[i]];
		cout << (solve(1,n) * c[m][n]) % MOD << endl;
	}

	return 0;
}