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


const int MAX_N = 409;
const int oo = 1e9;


int n, m, d[MAX_N];
bool a[MAX_N][MAX_N];
queue<int> q;


int solve(int val) {
	fori(i,1,n) d[i]=oo;
	d[1]=0;
	q.push(1);
	while (!q.empty()) {
		int u=q.front();	q.pop();
		fori(v,1,n) if (v!=u) {
			if (a[u][v]==val && d[u]+1<d[v]) {
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[n]>=oo ? -1 : max(d[n], 1);
}


int main() {
#ifdef DEBUG
	freopen("602C.in", "r", stdin);
	freopen("602C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	filla(a, 0);
	fori(i,1,m) {
		int x, y;
		cin >> x >> y;
		a[x][y]=a[y][x]=1;
	}
	cout << solve(a[1][n]^1) << endl;

	return 0;
}